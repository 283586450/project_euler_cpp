add_library(project_euler_core)

target_sources(
  project_euler_core
  PRIVATE project_euler/math.cpp
  PUBLIC FILE_SET HEADERS
         BASE_DIRS "${PROJECT_SOURCE_DIR}/include"
         FILES "${PROJECT_SOURCE_DIR}/include/project_euler/project_euler.hpp"
               "${PROJECT_SOURCE_DIR}/include/project_euler/math.hpp")

target_link_libraries(
  project_euler_core
  PUBLIC project_euler_options
         project_euler_warnings)

target_include_directories(project_euler_core PUBLIC "${PROJECT_SOURCE_DIR}/include")

