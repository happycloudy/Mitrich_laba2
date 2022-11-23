project(tests)

set(test1_source test1.cpp)
add_executable(test1 ${test1_source})
add_test(Test1 test1)

set(test2_source test2.cpp)
add_executable(test2 ${test2_source})
add_test(Test2 test2)