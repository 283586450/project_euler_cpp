add_executable(math_test math_test.cpp)

target_link_libraries(
  math_test
  PRIVATE project_euler_core
          project_euler_options
          project_euler_warnings)

add_test(NAME math_test COMMAND math_test)

