# Install script for directory: /Users/davide/Documents/Git/acme

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/Users/davide/Documents/Git/acme/lib")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/Users/davide/Documents/Git/acme/lib/dll/libacme_osx.dylib")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/Users/davide/Documents/Git/acme/lib/dll" TYPE SHARED_LIBRARY MESSAGE_NEVER FILES "/Users/davide/Documents/Git/acme/libacme_osx.dylib")
  if(EXISTS "$ENV{DESTDIR}/Users/davide/Documents/Git/acme/lib/dll/libacme_osx.dylib" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/Users/davide/Documents/Git/acme/lib/dll/libacme_osx.dylib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" -x "$ENV{DESTDIR}/Users/davide/Documents/Git/acme/lib/dll/libacme_osx.dylib")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/Users/davide/Documents/Git/acme/lib/lib/libacme_osx_static.a")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/Users/davide/Documents/Git/acme/lib/lib" TYPE STATIC_LIBRARY MESSAGE_NEVER FILES "/Users/davide/Documents/Git/acme/libacme_osx_static.a")
  if(EXISTS "$ENV{DESTDIR}/Users/davide/Documents/Git/acme/lib/lib/libacme_osx_static.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/Users/davide/Documents/Git/acme/lib/lib/libacme_osx_static.a")
    execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib" "$ENV{DESTDIR}/Users/davide/Documents/Git/acme/lib/lib/libacme_osx_static.a")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/Users/davide/Documents/Git/acme/lib/include/acme.hh;/Users/davide/Documents/Git/acme/lib/include/acme_AABBtree.hh;/Users/davide/Documents/Git/acme/lib/include/acme_aabb.hh;/Users/davide/Documents/Git/acme/lib/include/acme_circle.hh;/Users/davide/Documents/Git/acme/lib/include/acme_collinear.hh;/Users/davide/Documents/Git/acme/lib/include/acme_coplanar.hh;/Users/davide/Documents/Git/acme/lib/include/acme_entity.hh;/Users/davide/Documents/Git/acme/lib/include/acme_intersection.hh;/Users/davide/Documents/Git/acme/lib/include/acme_line.hh;/Users/davide/Documents/Git/acme/lib/include/acme_math.hh;/Users/davide/Documents/Git/acme/lib/include/acme_none.hh;/Users/davide/Documents/Git/acme/lib/include/acme_orthogonal.hh;/Users/davide/Documents/Git/acme/lib/include/acme_parallel.hh;/Users/davide/Documents/Git/acme/lib/include/acme_plane.hh;/Users/davide/Documents/Git/acme/lib/include/acme_point.hh;/Users/davide/Documents/Git/acme/lib/include/acme_ray.hh;/Users/davide/Documents/Git/acme/lib/include/acme_segment.hh;/Users/davide/Documents/Git/acme/lib/include/acme_sphere.hh;/Users/davide/Documents/Git/acme/lib/include/acme_triangle.hh;/Users/davide/Documents/Git/acme/lib/include/acme_utils.hh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/Users/davide/Documents/Git/acme/lib/include" TYPE FILE MESSAGE_NEVER FILES
    "/Users/davide/Documents/Git/acme/include/acme.hh"
    "/Users/davide/Documents/Git/acme/include/acme_AABBtree.hh"
    "/Users/davide/Documents/Git/acme/include/acme_aabb.hh"
    "/Users/davide/Documents/Git/acme/include/acme_circle.hh"
    "/Users/davide/Documents/Git/acme/include/acme_collinear.hh"
    "/Users/davide/Documents/Git/acme/include/acme_coplanar.hh"
    "/Users/davide/Documents/Git/acme/include/acme_entity.hh"
    "/Users/davide/Documents/Git/acme/include/acme_intersection.hh"
    "/Users/davide/Documents/Git/acme/include/acme_line.hh"
    "/Users/davide/Documents/Git/acme/include/acme_math.hh"
    "/Users/davide/Documents/Git/acme/include/acme_none.hh"
    "/Users/davide/Documents/Git/acme/include/acme_orthogonal.hh"
    "/Users/davide/Documents/Git/acme/include/acme_parallel.hh"
    "/Users/davide/Documents/Git/acme/include/acme_plane.hh"
    "/Users/davide/Documents/Git/acme/include/acme_point.hh"
    "/Users/davide/Documents/Git/acme/include/acme_ray.hh"
    "/Users/davide/Documents/Git/acme/include/acme_segment.hh"
    "/Users/davide/Documents/Git/acme/include/acme_sphere.hh"
    "/Users/davide/Documents/Git/acme/include/acme_triangle.hh"
    "/Users/davide/Documents/Git/acme/include/acme_utils.hh"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/Users/davide/Documents/Git/acme/lib/include/acme.hh;/Users/davide/Documents/Git/acme/lib/include/acme_AABBtree.hh;/Users/davide/Documents/Git/acme/lib/include/acme_aabb.hh;/Users/davide/Documents/Git/acme/lib/include/acme_circle.hh;/Users/davide/Documents/Git/acme/lib/include/acme_collinear.hh;/Users/davide/Documents/Git/acme/lib/include/acme_coplanar.hh;/Users/davide/Documents/Git/acme/lib/include/acme_entity.hh;/Users/davide/Documents/Git/acme/lib/include/acme_intersection.hh;/Users/davide/Documents/Git/acme/lib/include/acme_line.hh;/Users/davide/Documents/Git/acme/lib/include/acme_math.hh;/Users/davide/Documents/Git/acme/lib/include/acme_none.hh;/Users/davide/Documents/Git/acme/lib/include/acme_orthogonal.hh;/Users/davide/Documents/Git/acme/lib/include/acme_parallel.hh;/Users/davide/Documents/Git/acme/lib/include/acme_plane.hh;/Users/davide/Documents/Git/acme/lib/include/acme_point.hh;/Users/davide/Documents/Git/acme/lib/include/acme_ray.hh;/Users/davide/Documents/Git/acme/lib/include/acme_segment.hh;/Users/davide/Documents/Git/acme/lib/include/acme_sphere.hh;/Users/davide/Documents/Git/acme/lib/include/acme_triangle.hh;/Users/davide/Documents/Git/acme/lib/include/acme_utils.hh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/Users/davide/Documents/Git/acme/lib/include" TYPE FILE MESSAGE_NEVER FILES
    "/Users/davide/Documents/Git/acme/include/acme.hh"
    "/Users/davide/Documents/Git/acme/include/acme_AABBtree.hh"
    "/Users/davide/Documents/Git/acme/include/acme_aabb.hh"
    "/Users/davide/Documents/Git/acme/include/acme_circle.hh"
    "/Users/davide/Documents/Git/acme/include/acme_collinear.hh"
    "/Users/davide/Documents/Git/acme/include/acme_coplanar.hh"
    "/Users/davide/Documents/Git/acme/include/acme_entity.hh"
    "/Users/davide/Documents/Git/acme/include/acme_intersection.hh"
    "/Users/davide/Documents/Git/acme/include/acme_line.hh"
    "/Users/davide/Documents/Git/acme/include/acme_math.hh"
    "/Users/davide/Documents/Git/acme/include/acme_none.hh"
    "/Users/davide/Documents/Git/acme/include/acme_orthogonal.hh"
    "/Users/davide/Documents/Git/acme/include/acme_parallel.hh"
    "/Users/davide/Documents/Git/acme/include/acme_plane.hh"
    "/Users/davide/Documents/Git/acme/include/acme_point.hh"
    "/Users/davide/Documents/Git/acme/include/acme_ray.hh"
    "/Users/davide/Documents/Git/acme/include/acme_segment.hh"
    "/Users/davide/Documents/Git/acme/include/acme_sphere.hh"
    "/Users/davide/Documents/Git/acme/include/acme_triangle.hh"
    "/Users/davide/Documents/Git/acme/include/acme_utils.hh"
    )
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/Users/davide/Documents/Git/acme/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
