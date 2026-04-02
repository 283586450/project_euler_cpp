cmake_minimum_required(VERSION 3.24)

project(project_euler_cpp VERSION 0.1.0 LANGUAGES CXX)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

option(PROJECT_EULER_ENABLE_CLANG_TIDY "Enable clang-tidy during builds" OFF)

include(CTest)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(ProjectOptions)
include(CompilerWarnings)
include(AddEulerProblem)

project_euler_setup_options()
project_euler_setup_warnings()

if(PROJECT_EULER_ENABLE_CLANG_TIDY)
  find_program(PROJECT_EULER_CLANG_TIDY_EXE NAMES clang-tidy clang-tidy.exe)
  if(NOT PROJECT_EULER_CLANG_TIDY_EXE)
    message(FATAL_ERROR "PROJECT_EULER_ENABLE_CLANG_TIDY is ON, but clang-tidy was not found")
  endif()

  set(CMAKE_CXX_CLANG_TIDY "${PROJECT_EULER_CLANG_TIDY_EXE}")
endif()

add_subdirectory(src)
add_subdirectory(problems)

if(BUILD_TESTING)
  add_subdirectory(tests)
endif()
