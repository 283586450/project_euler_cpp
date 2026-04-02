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

add_test(NAME problem_0003 COMMAND project_euler_problem_0003)
set_tests_properties(problem_0003 PROPERTIES PASS_REGULAR_EXPRESSION "6857")

add_test(NAME problem_0004 COMMAND project_euler_problem_0004)
set_tests_properties(problem_0004 PROPERTIES PASS_REGULAR_EXPRESSION "906609")

add_test(NAME problem_0005 COMMAND project_euler_problem_0005)
set_tests_properties(problem_0005 PROPERTIES PASS_REGULAR_EXPRESSION "232792560")

add_test(NAME problem_0006 COMMAND project_euler_problem_0006)
set_tests_properties(problem_0006 PROPERTIES PASS_REGULAR_EXPRESSION "25164150")

add_test(NAME problem_0007 COMMAND project_euler_problem_0007)
set_tests_properties(problem_0007 PROPERTIES PASS_REGULAR_EXPRESSION "104743")

add_test(NAME problem_0008 COMMAND project_euler_problem_0008)
set_tests_properties(problem_0008 PROPERTIES PASS_REGULAR_EXPRESSION "23514624000")

add_test(NAME problem_0009 COMMAND project_euler_problem_0009)
set_tests_properties(problem_0009 PROPERTIES PASS_REGULAR_EXPRESSION "31875000")

add_test(NAME problem_0010 COMMAND project_euler_problem_0010)
set_tests_properties(problem_0010 PROPERTIES PASS_REGULAR_EXPRESSION "142913828922")

add_test(NAME problem_0011 COMMAND project_euler_problem_0011)
set_tests_properties(problem_0011 PROPERTIES PASS_REGULAR_EXPRESSION "70600674")

add_test(NAME problem_0012 COMMAND project_euler_problem_0012)
set_tests_properties(problem_0012 PROPERTIES PASS_REGULAR_EXPRESSION "76576500")

add_test(NAME problem_0013 COMMAND project_euler_problem_0013)
set_tests_properties(problem_0013 PROPERTIES PASS_REGULAR_EXPRESSION "5537376230")

add_test(NAME problem_0014 COMMAND project_euler_problem_0014)
set_tests_properties(problem_0014 PROPERTIES PASS_REGULAR_EXPRESSION "837799")

add_test(NAME problem_0015 COMMAND project_euler_problem_0015)
set_tests_properties(problem_0015 PROPERTIES PASS_REGULAR_EXPRESSION "137846528820")

add_test(NAME problem_0016 COMMAND project_euler_problem_0016)
set_tests_properties(problem_0016 PROPERTIES PASS_REGULAR_EXPRESSION "1366")

add_test(NAME problem_0017 COMMAND project_euler_problem_0017)
set_tests_properties(problem_0017 PROPERTIES PASS_REGULAR_EXPRESSION "21124")

add_test(NAME problem_0018 COMMAND project_euler_problem_0018)
set_tests_properties(problem_0018 PROPERTIES PASS_REGULAR_EXPRESSION "1074")

add_test(NAME problem_0019 COMMAND project_euler_problem_0019)
set_tests_properties(problem_0019 PROPERTIES PASS_REGULAR_EXPRESSION "171")

add_test(NAME problem_0020 COMMAND project_euler_problem_0020)
set_tests_properties(problem_0020 PROPERTIES PASS_REGULAR_EXPRESSION "648")

add_test(NAME problem_0021 COMMAND project_euler_problem_0021)
set_tests_properties(problem_0021 PROPERTIES PASS_REGULAR_EXPRESSION "31626")

add_test(NAME problem_0022 COMMAND project_euler_problem_0022)
set_tests_properties(problem_0022 PROPERTIES PASS_REGULAR_EXPRESSION "871198282")

add_test(NAME problem_0023 COMMAND project_euler_problem_0023)
set_tests_properties(problem_0023 PROPERTIES PASS_REGULAR_EXPRESSION "4179871")

add_test(NAME problem_0024 COMMAND project_euler_problem_0024)
set_tests_properties(problem_0024 PROPERTIES PASS_REGULAR_EXPRESSION "2783915460")

add_test(NAME problem_0025 COMMAND project_euler_problem_0025)
set_tests_properties(problem_0025 PROPERTIES PASS_REGULAR_EXPRESSION "4782")

add_test(NAME problem_0026 COMMAND project_euler_problem_0026)
set_tests_properties(problem_0026 PROPERTIES PASS_REGULAR_EXPRESSION "983")

add_test(NAME problem_0027 COMMAND project_euler_problem_0027)
set_tests_properties(problem_0027 PROPERTIES PASS_REGULAR_EXPRESSION "-59231")

add_test(NAME problem_0028 COMMAND project_euler_problem_0028)
set_tests_properties(problem_0028 PROPERTIES PASS_REGULAR_EXPRESSION "669171001")

add_test(NAME problem_0029 COMMAND project_euler_problem_0029)
set_tests_properties(problem_0029 PROPERTIES PASS_REGULAR_EXPRESSION "9183")

add_test(NAME problem_0030 COMMAND project_euler_problem_0030)
set_tests_properties(problem_0030 PROPERTIES PASS_REGULAR_EXPRESSION "443839")
