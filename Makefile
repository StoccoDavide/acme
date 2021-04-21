# (***********************************************************************)
# (*                                                                     *)
# (* The ACME computational geometry library                             *)
# (* Release Version 0.0.0                                               *)
# (* Copyright (c) 2020-2021 Davide Stocco, All Rights Reserved.         *)
# (*                                                                     *)
# (* The ACME computational geometry library and its components are      *)
# (* supplied under the terms of the open source MIT License.            *)
# (* The contents of the ACME computational geometry library and its     *)
# (* components may not be copied or disclosed except in accordance with *)
# (* the terms of the MIT License.                                       *)
# (*                                                                     *)
# (* URL: https://opensource.org/licenses/MIT                            *)
# (*                                                                     *)
# (***********************************************************************)

OS  = $(shell uname -s)
PWD = $(shell pwd)

SOURCES       = $(wildcard src/*.cc)
OBJECTS       = $(patsubst src/%.cc, build/%.o, $(SOURCES))
TESTS_SOURCES = $(wildcard tests/*.cc)
INCLUDEDIRS   = -Iinclude -Isubmodules/acme/lib/include

CXXFLAGS      = $(INCLUDEDIRS) $(shell pkg-config --cflags eigen3) 
LIBS          = 
DEFS          =
STATIC_EXT    = .a
DYNAMIC_EXT   = .so

# check if the OS string contains 'Linux'
ifneq (,$(findstring Linux, $(OS)))
	CC        = gcc
	CXX       = g++
	LIBS     += 
	CXXFLAGS += -g -std=c++11 $(WARN) -O2 -fPIC -Wall -Wpedantic -Wextra -Wno-comment $(RPATH)
	AR        = ar rcs
	LDCONFIG  = sudo ldconfig
endif

# check if the OS string contains 'MINGW'
ifneq (,$(findstring MINGW, $(OS)))
	LIBS     += 
	CXXFLAGS += -g -std=c++11 $(WARN) -O2 -fPIC -Wall -Wpedantic -Wextra -Wno-comment
	AR        = ar rcs
	LDCONFIG  = sudo ldconfig
endif

# check if the OS string contains 'Darwin'
ifneq (,$(findstring Darwin, $(OS)))
	LIBS       +=
	WARN        = -Wall -Wno-sign-compare -Wno-global-constructors -Wno-padded -Wno-documentation-unknown-command
	CC          = clang
	CXX         = clang++ -std=c++11 -g
	CXXFLAGS   += $(WARN) -O2 -fPIC
	AR          = libtool -static -o
	LDCONFIG    = 
	DYNAMIC_EXT = .dylib
endif

LIB_ACME = libacme
MKDIR = mkdir -p
DEPS  = include/acme.hh include/acme_AABBtree.hh include/acme_box.hh

# prefix for installation, use make PREFIX=/new/prefix install
# to override
PREFIX    = /usr/local
FRAMEWORK = acme

all: $(OBJECTS)

lib: lib/$(LIB_ACME)$(STATIC_EXT) lib/$(LIB_ACME)$(DYNAMIC_EXT)

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
	$(AR) lib/libacme_static.a $(OBJECTS)

lib/libacme.dylib: $(OBJECTS) include_local
	@$(MKDIR) lib
	$(CXX) -shared -o lib/libacme.dylib $(OBJECTS)

lib/libacme.so: $(OBJECTS) include_local
	@$(MKDIR) lib
	$(CXX) -shared -o lib/libacme.so $(OBJECTS)

install: lib
	@$(MKDIR) $(PREFIX)/lib
	@$(MKDIR) $(PREFIX)/include
	cp include/*.hh        $(PREFIX)/include
	cp lib/$(LIB_ACME).*   $(PREFIX)/lib
	@$(LDCONFIG) $(PREFIX)/lib

install_as_framework: lib
	@$(MKDIR) $(PREFIX)/lib
	@$(MKDIR) $(PREFIX)/include/$(FRAMEWORK)
	cp include/*.hh    $(PREFIX)/include/$(FRAMEWORK)
	cp lib/$(LIB_ACME) $(PREFIX)/lib

dir:
	mkdir -p build
	mkdir -p bin

build/%.o: src/%.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rf $(TARGET)
	rm -rf $(OBJECTS)

tests: $(OBJECTS) $(TESTS_SOURCES)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) tests/acme-test0.cc  -o bin/acme-test0  $(LIBS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) tests/acme-test1.cc  -o bin/acme-test1  $(LIBS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) tests/acme-test2.cc  -o bin/acme-test2  $(LIBS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) tests/acme-test3.cc  -o bin/acme-test3  $(LIBS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) tests/acme-test4.cc  -o bin/acme-test4  $(LIBS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) tests/acme-test5.cc  -o bin/acme-test5  $(LIBS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) tests/acme-test6.cc  -o bin/acme-test6  $(LIBS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) tests/acme-test7.cc  -o bin/acme-test7  $(LIBS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) tests/acme-test8.cc  -o bin/acme-test8  $(LIBS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) tests/acme-test9.cc  -o bin/acme-test9  $(LIBS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) tests/acme-test10.cc  -o bin/acme-test10  $(LIBS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) tests/acme-test11.cc  -o bin/acme-test11  $(LIBS)

tests_run:
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

#
# That's All Folks!
#
