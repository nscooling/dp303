# Copyright (c) <year> <author> (<email>)
# Distributed under the MIT License.
# See accompanying file LICENSE.md or copy at http://opensource.org/licenses/MIT

cmake_minimum_required(VERSION 2.6)

set(PROJECT_NAME			       "dp303")
project(${PROJECT_NAME} C CXX)

set(PROJECT_PATH                               "${CMAKE_CURRENT_SOURCE_DIR}")

# while all exercise code is stored in src directory
set(INCLUDE_PATH                               "${PROJECT_PATH}/src")
set(SRC_PATH                                   "${PROJECT_PATH}/src")

set(BIN_PATH                                   "${PROJECT_BINARY_DIR}/bin")
set(MAIN_NAME                                  "${PROJECT_NAME}_main")

OPTION(BUILD_MAIN                              "Build main function"            ON)

if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS_DEBUG   "-O0 -g3")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3")
    set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
endif(CMAKE_COMPILER_IS_GNUCXX)

include(FeabhOSProjectFiles.cmake)
include(ProjectFiles.cmake)
include_directories(AFTER "${INCLUDE_PATH}")

if(BUILD_MAIN)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_PATH})
  add_executable(${MAIN_NAME} ${MAIN_SRC} ${SRC})
  target_link_libraries(${MAIN_NAME} ${LIB_NAME} pthread)
endif(BUILD_MAIN)
