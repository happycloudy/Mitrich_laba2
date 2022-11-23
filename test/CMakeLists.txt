project(tests)

set(intTest_source intTest.cpp)
add_executable(intTest ${intTest_source})
add_test(IntTest intTest)

set(resultTest_source resultTest.cpp)
add_executable(resultTest ${resultTest_source})
add_test(ResultTest resultTest)

set(test1_source test1.cpp)
add_executable(test1 ${test1_source})
add_test(RunTest1 test1)

set(test2_source test2.cpp)
add_executable(test2 ${test2_source})
add_test(RunTest2 test2)

set(test3_source test3.cpp)
add_executable(test3 ${test3_source})
add_test(RunTest3 test3)

set(test4_source test4.cpp)
add_executable(test4 ${test4_source})
add_test(RunTest4 test4)

