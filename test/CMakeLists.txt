project(tests)

set(test1_source test1.cpp)
add_executable(test1 ${test1_source})
add_test(Test1 test1)

set(test2_source test2.cpp)
add_executable(test2 ${test2_source})
add_test(Test2 test2)

set(test3_source test3.cpp)
add_executable(test3 ${test3_source})
add_test(Test3 test3)

set(test4_source test4.cpp)
add_executable(test4 ${test4_source})
add_test(Test4 test4)