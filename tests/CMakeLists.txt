add_executable(math_test math_test.cpp)

target_link_libraries(
  math_test
  PRIVATE project_euler_core
          project_euler_options
          project_euler_warnings)

add_test(NAME math_test COMMAND math_test)

add_test(NAME problem_0001 COMMAND project_euler_problem_0001)
set_tests_properties(problem_0001 PROPERTIES PASS_REGULAR_EXPRESSION "233168")

add_test(NAME problem_0002 COMMAND project_euler_problem_0002)
set_tests_properties(problem_0002 PROPERTIES PASS_REGULAR_EXPRESSION "4613732")
