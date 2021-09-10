# (***********************************************************************)
# (*                                                                     *)
# (* The ACME project                                                    *)
# (*                                                                     *)
# (* Copyright (c) 2020-2021, Davide Stocco and Enrico Bertolazzi.       *)
# (*                                                                     *)
# (* The ACME project and its components are supplied under the terms of *)
# (* the open source BSD 2-Clause License. The contents of the ACME      *)
# (* project and its components may not be copied or disclosed except in *)
# (* accordance with the terms of the BSD 2-Clause License.              *)
# (*                                                                     *)
# (* URL: https://opensource.org/licenses/BSD-2-Clause                   *)
# (*                                                                     *)
# (*    Davide Stocco                                                    *)
# (*    Department of Industrial Engineering                             *)
# (*    University of Trento                                             *)
# (*    e-mail: davide.stocco@unitn.it                                   *)
# (*                                                                     *)
# (*    Enrico Bertolazzi                                                *)
# (*    Department of Industrial Engineering                             *)
# (*    University of Trento                                             *)
# (*    e-mail: enrico.bertolazzi@unitn.it                               *)
# (*                                                                     *)
# (***********************************************************************)

OS  = $(shell uname -s)
PWD = $(shell pwd)

SOURCES       = $(wildcard src/*.cc)
OBJECTS       = $(patsubst src/%.cc, build/%.o, $(SOURCES))
TESTS_SOURCES = $(wildcard tests/*.cc)
INCLUDEDIRS   = -Iinclude -Isubmodules/acme/lib/include

CXXFLAGS    = $(INCLUDEDIRS) $(shell pkg-config --cflags eigen3) 
LIBS        =
DEFS        =
STATIC_EXT  = .a
DYNAMIC_EXT = .so

# check if the OS string contains 'Linux'
ifneq (,$(findstring Linux, $(OS)))
  LIBS     += #-static -L./lib -lacme
  CXXFLAGS += -g -std=c++11 $(WARN) -O2 -fPIC -Wall -Wpedantic -Wextra -Wno-comment $(RPATH)
  AR       = ar rcs
  LDCONFIG = sudo ldconfig
endif

# check if the OS string contains 'MINGW'
ifneq (,$(findstring MINGW, $(OS)))
  LIBS     += #-static -L./lib -lacme
  CXXFLAGS += -g -std=c++11 $(WARN) -O2 -fPIC -Wall -Wpedantic -Wextra -Wno-comment
  AR        = ar rcs
  LDCONFIG  = sudo ldconfig
endif

# check if the OS string contains 'Darwin'
ifneq (,$(findstring Darwin, $(OS)))
  LIBS += #-L./lib -lacme
  WARN  = -Wall -Wno-sign-compare -Wno-global-constructors -Wno-padded -Wno-documentation-unknown-command
  CC          = clang
  CXX         = clang++ -std=c++14 -g
  CXXFLAGS   += $(WARN) -O2 -fPIC
  AR          = libtool -static -o
  LDCONFIG    = 
  DYNAMIC_EXT = .dylib
endif

LIB_ACME = libacme
MKDIR = mkdir -p
DEPS  = \
include/acme_aabb.hh         \
include/acme_AABBtree.hh     \
include/acme_disk.hh         \
include/acme_collection.hh   \
include/acme_collinear.hh    \
include/acme_coplanar.hh     \
include/acme_entity.hh       \
include/acme_intersection.hh \
include/acme_line.hh         \
include/acme_math.hh         \
include/acme_none.hh         \
include/acme_orthogonal.hh   \
include/acme_parallel.hh     \
include/acme_plane.hh        \
include/acme_point.hh        \
include/acme_ray.hh          \
include/acme_segment.hh      \
include/acme_triangle.hh     \
include/acme_utils.hh        \
include/acme.hh              \

# prefix for installation, use make PREFIX=/new/prefix install
# to override
PREFIX    = /usr/local
FRAMEWORK = acme


all: dir $(OBJECTS)

lib: dir lib/$(LIB_ACME)$(STATIC_EXT) lib/$(LIB_ACME)$(DYNAMIC_EXT)

include_local:
	@rm -rf lib/include
	$(MKDIR) lib
	$(MKDIR) lib/include
	@cp -f include/*.hh lib/include

src/%.o: src/%.cc $(DEPS)
	$(CXX) $(INC) $(CXXFLAGS) $(DEFS) -c $< -o $@

src/%.o: build/%.c $(DEPS)
	$(CC) $(INC) $(CFLAGS) $(DEFS) -c -o $@ $<

lib/libacme.a: $(OBJECTS) include_local
	@$(MKDIR) lib
	$(AR) lib/$(LIB_ACME)_static.a $(OBJECTS)

lib/libacme.dylib: $(OBJECTS) include_local
	@$(MKDIR) lib
	$(CXX) -shared -o lib/$(LIB_ACME).dylib $(OBJECTS)

lib/libacme.so: $(OBJECTS) include_local
	@$(MKDIR) lib
	$(CXX) -shared -o lib/$(LIB_ACME).so $(OBJECTS)

install: lib
	@$(MKDIR) $(PREFIX)/lib
	@$(MKDIR) $(PREFIX)/include
	cp include/*.hh      $(PREFIX)/include
	cp lib/$(LIB_ACME).* $(PREFIX)/lib
	@$(LDCONFIG)         $(PREFIX)/lib

install_as_framework: lib
	@$(MKDIR) $(PREFIX)/lib
	@$(MKDIR) $(PREFIX)/include/$(FRAMEWORK)
	cp include/*.hh    $(PREFIX)/include/$(FRAMEWORK)
	cp lib/$(LIB_ACME) $(PREFIX)/lib

dir:
	@$(MKDIR) build
	@$(MKDIR) bin

build/%.o: src/%.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rf $(TARGET)
	rm -rf $(OBJECTS)

worked_example: dir $(OBJECTS) $(TESTS_SOURCES)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) tests/paper_worked_example.cc -o bin/paper_worked_example $(LIBS)
	./bin/paper_worked_example

tests: dir $(OBJECTS) $(TESTS_SOURCES)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) tests/acme-test0.cc -o bin/acme-test0 $(LIBS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) tests/acme-test1.cc -o bin/acme-test1 $(LIBS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) tests/acme-test2.cc -o bin/acme-test2 $(LIBS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) tests/acme-test3.cc -o bin/acme-test3 $(LIBS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) tests/acme-test4.cc -o bin/acme-test4 $(LIBS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) tests/acme-test5.cc -o bin/acme-test5 $(LIBS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) tests/acme-test6.cc -o bin/acme-test6 $(LIBS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) tests/acme-test7.cc -o bin/acme-test7 $(LIBS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) tests/acme-test8.cc -o bin/acme-test8 $(LIBS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) tests/acme-test9.cc -o bin/acme-test9 $(LIBS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) tests/acme-test10.cc -o bin/acme-test10 $(LIBS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) tests/acme-test11.cc -o bin/acme-test11 $(LIBS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) tests/acme-test12.cc -o bin/acme-test12 $(LIBS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) tests/acme-test13.cc -o bin/acme-test13 $(LIBS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) tests/acme-test14.cc -o bin/acme-test14 $(LIBS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) tests/acme-test15.cc -o bin/acme-test15 $(LIBS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) tests/acme-test16.cc -o bin/acme-test16 $(LIBS)

run:
	./bin/acme-test0
	./bin/acme-test1
	./bin/acme-test2
	./bin/acme-test3
	./bin/acme-test4
	./bin/acme-test5
	./bin/acme-test6
	./bin/acme-test7
	./bin/acme-test8
	./bin/acme-test9
	./bin/acme-test10
	./bin/acme-test11
	./bin/acme-test12
	./bin/acme-test13
	./bin/acme-test14
	./bin/acme-test15
	./bin/acme-test16

acme_vs_cgal: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) tests/acme_vs_cgal/line-line.cc -o bin/line-line $(LIBS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) tests/acme_vs_cgal/ray-ray.cc -o bin/ray-ray $(LIBS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) tests/acme_vs_cgal/segment-segment.cc -o bin/segment-segment $(LIBS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) tests/acme_vs_cgal/line-ray.cc -o bin/line-ray $(LIBS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) tests/acme_vs_cgal/line-segment.cc -o bin/line-segment $(LIBS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) tests/acme_vs_cgal/line-triangle.cc -o bin/line-triangle $(LIBS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) tests/acme_vs_cgal/ray-triangle.cc -o bin/ray-triangle $(LIBS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) tests/acme_vs_cgal/segment-triangle.cc -o bin/segment-triangle $(LIBS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) tests/acme_vs_cgal/triangle-triangle.cc -o bin/triangle-triangle $(LIBS)

acme_vs_cgal_run:
	./bin/line-line
	./bin/ray-ray
	./bin/segment-segment
	./bin/triangle-triangle
	./bin/line-ray
	./bin/line-segment
	./bin/line-triangle
	./bin/ray-triangle
	./bin/segment-triangle

#
# That's All Folks!
#