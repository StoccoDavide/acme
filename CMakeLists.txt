# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                                                                     #
# The ACME project                                                    #
#                                                                     #
# Copyright (c) 2020, Davide Stocco and Enrico Bertolazzi.            #
#                                                                     #
# The ACME project and its components are supplied under the terms of #
# the open source BSD 2-Clause License. The contents of the ACME      #
# project and its components may not be copied or disclosed except in #
# accordance with the terms of the BSD 2-Clause License.              #
#                                                                     #
# URL: https://opensource.org/licenses/BSD-2-Clause                   #
#                                                                     #
#    Davide Stocco                                                    #
#    Department of Industrial Engineering                             #
#    University of Trento                                             #
#    e-mail: davide.stocco@unitn.it                                   #
#                                                                     #
#    Enrico Bertolazzi                                                #
#    Department of Industrial Engineering                             #
#    University of Trento                                             #
#    e-mail: enrico.bertolazzi@unitn.it                               #
#                                                                     #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

cmake_minimum_required(VERSION 3.14)

project( acme )
include(./cmake_utils/CMakeLists-common.txt)

project(
  ${PROJECT_NAME}
  VERSION ${UTILS_PROJECT_VERSION}
  HOMEPAGE_URL "https://StoccoDavide.github.io/acme/"
)

include(./CMakeLists-cflags.txt)
include(./cmake_utils/CMakeLists-utilities.txt)

# Evaluating the suffix to append to target built by this CMake file
utils_artifacts_suffix(ARTIFACTS_STATIC_SUFFIX TRUE)
if( UTILS_BUILD_SHARED )
  utils_artifacts_suffix(ARTIFACTS_DYNAMIC_SUFFIX FALSE)
endif()

message( STATUS "Compiler used: ${CMAKE_CXX_COMPILER_ID}" )
message( STATUS "BASE SUFFIXES = ${ARTIFACTS_STATIC_SUFFIX} ${ARTIFACTS_DYNAMIC_SUFFIX}" )

#   ____
#  / ___|  ___  _   _ _ __ ___ ___  ___
#  \___ \ / _ \| | | | '__/ __/ _ \/ __|
#   ___) | (_) | |_| | | | (_|  __/\__ \
#  |____/ \___/ \__,_|_|  \___\___||___/
#

set( SOURCES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src" )

set( SOURCES )
file( GLOB S ${SOURCES_DIR}/*.cc )
foreach(F ${S})
  # Build relative path respect to source directory
  file( RELATIVE_PATH RF ${SOURCES_DIR} "${F}" )
  list( APPEND SOURCES ${RF} )
endforeach(F ${S})

#   _   _                _
#  | | | | ___  __ _  __| | ___ _ __ ___
#  | |_| |/ _ \/ _` |/ _` |/ _ \ '__/ __|
#  |  _  |  __/ (_| | (_| |  __/ |  \__ \
#  |_| |_|\___|\__,_|\__,_|\___|_|  |___/
#

set( HEADERS )
file( GLOB S
  ${SOURCES_DIR}/*.h*
  ${SOURCES_DIR}/acme/*.h*
)
foreach (F ${S})
  # Build relative path respect to include directory
  file( RELATIVE_PATH RF ${SOURCES_DIR} "${F}" )
  list( APPEND HEADERS ${RF} )
endforeach(F ${S})

# Extra include directory for compilation
include_directories( ${SOURCES_DIR} ./lib3rd/include ) # FIXME: ${SOURCES_DIR}

#   _____ _
#  | ____(_) __ _  ___ _ __
#  |  _| | |/ _` |/ _ \ '_ \
#  | |___| | (_| |  __/ | | |
#  |_____|_|\__, |\___|_| |_|
#           |___/

find_package(Eigen3 REQUIRED)
include_directories( ${EIGEN3_INCLUDE_DIR} )
message("Eigen include directories: ${EIGEN3_INCLUDE_DIR}")
message("Eigen include directories: ${EIGEN3_FOUND}")

#   _____                    _
#  |_   _|_ _ _ __ __ _  ___| |_ ___
#    | |/ _` | '__/ _` |/ _ \ __/ __|
#    | | (_| | | | (_| |  __/ |_\__ \
#    |_|\__,_|_|  \__, |\___|\__|___/
#                 |___/

# Define target
utils_setup_target(
  ${PROJECT_NAME}
  TRUE # Build static
  "${SOURCES_DIR}"
  "${SOURCES}"
  "${SOURCES_DIR}"
  "${HEADERS}"
)
if ( UTILS_BUILD_SHARED )
  utils_setup_target(
    ${PROJECT_NAME}
    FALSE # Build dynamic
    "${SOURCES_DIR}"
    "${SOURCES}"
    "${SOURCES_DIR}"
    "${HEADERS}"
  )
  target_link_libraries( ${UTILS_NAMESPACE}_${PROJECT_NAME} ${UTILS} )
endif()

if ( DEPEND_TARGETS )
  add_dependencies( ${UTILS_NAMESPACE}_${PROJECT_NAME}_Static ${DEPEND_TARGETS} )
endif()

#   _____         _
#  |_   _|__  ___| |_ ___
#    | |/ _ \/ __| __/ __|
#    | |  __/\__ \ |_\__ \
#    |_|\___||___/\__|___/
#

if ( UTILS_ENABLE_TESTS )

  enable_testing()

  if(APPLE OR UNIX OR MINGW )
    find_package( ZLIB REQUIRED )
  else()
    if ( CMAKE_BUILD_TYPE STREQUAL "Debug" )
      find_library( ZLIB_LIBRARIES zlibstaticd HINTS ./lib3rd/lib )
    else()
      find_library( ZLIB_LIBRARIES zlibstatic HINTS ./lib3rd/lib )
    endif()
    set( ZLIB_SOURCES_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/lib3rd/zlib/include ")
  endif()

  set( LIBS ${UTILS_NAMESPACE}_${PROJECT_NAME}_Static ${UTILS} ${ZLIB_LIBRARIES} ${CMAKE_DL_LIBS} )

  if( UNIX )
    if ( NOT APPLE )
      set( THREADS_PREFER_PTHREAD_FLAG ON )
      find_package( Threads REQUIRED )
      set( LIBS ${LIBS} Threads::Threads )
    endif()
  else()
    set( LIBS ${LIBS} ws2_32 iphlpapi kernel32 )
    if (UTILS_BUILD_SHARED)
      target_link_libraries( ${UTILS_NAMESPACE}_${PROJECT_NAME} ${LIBS} Eigen3::Eigen ${ZLIB_LIBRARIES} ${CMAKE_DL_LIBS} )
    endif()
  endif()

  set(
    # List of tests to be executed
    EXELISTCPP
    acme_test_00
    acme_test_01
    acme_test_02
    acme_test_03
    acme_test_04
    acme_test_05
    acme_test_06
    acme_test_07
    acme_test_08
    acme_test_09
    acme_test_10
    acme_test_11
    acme_test_12
    acme_test_13
    acme_test_14
    acme_test_15
    acme_test_16
    acme_test_17
    acme_test_18
  )

  add_custom_target( "${PROJECT_NAME}_all_tests" ALL )

  # Set bin folder
  set( EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin )

  # Set tests folder
  foreach( S ${EXELISTCPP} )
    add_executable( ${S} ${CMAKE_CURRENT_SOURCE_DIR}/tests/${S}.cc )
    target_link_libraries( ${S} ${LIBS} )
    set_target_properties( ${S} PROPERTIES SUFFIX ".exe" )
    add_test( NAME "${S}" COMMAND ./bin/${S}.exe WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} )
    add_dependencies( "${PROJECT_NAME}_all_tests" ${S} )
  endforeach()

endif()

#   ___           _        _ _
#  |_ _|_ __  ___| |_ __ _| | |
#   | || '_ \/ __| __/ _` | | |
#   | || | | \__ \ || (_| | | |
#  |___|_| |_|___/\__\__,_|_|_|
#

install(
  TARGETS ${TARGETS_TO_BE_INSTALLED}
  # Export (to be defined)
  LIBRARY DESTINATION ${INSTALL_PREFIX}/dll
  ARCHIVE DESTINATION ${INSTALL_PREFIX}/lib
  RUNTIME DESTINATION ${INSTALL_PREFIX}/bin
  PUBLIC_HEADER DESTINATION ${PROJECT_PUBLIC_HEADER_DESTINATION}
)

#   ____            _
#  |  _ \ __ _  ___| | ____ _  __ _  ___
#  | |_) / _` |/ __| |/ / _` |/ _` |/ _ \
#  |  __/ (_| | (__|   < (_| | (_| |  __/
#  |_|   \__,_|\___|_|\_\__,_|\__, |\___|
#                             |___/

include( ./cmake_utils/CMakeLists-cpack.txt )

utils_final_messages()

#
# That's all Folks!
#
