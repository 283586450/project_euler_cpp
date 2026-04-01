cmake_minimum_required(VERSION 3.24)

project(project_euler_cpp VERSION 0.1.0 LANGUAGES CXX)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

include(CTest)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(ProjectOptions)
include(CompilerWarnings)
include(AddEulerProblem)

project_euler_setup_options()
project_euler_setup_warnings()

add_subdirectory(src)
add_subdirectory(problems)

if(BUILD_TESTING)
  add_subdirectory(tests)
endif()

