project(tests)

set(intTest_source intTest.cpp)
add_executable(intTest ${intTest_source})
add_test(IntTest intTest)

set(resultTest_source resultTest.cpp)
add_executable(resultTest ${resultTest_source})
add_test(ResultTest resultTest)

set(test1_source runTest_1.cpp)
add_executable(test1 ${test1_source})
add_test(RunTest1Thread test1)

set(test2_source runTest_2.cpp)
add_executable(test2 ${test2_source})
add_test(RunTest2Threads test2)

set(test3_source runTest_4.cpp)
add_executable(test3 ${test3_source})
add_test(RunTest4Threads test3)

set(test4_source runTest_8.cpp)
add_executable(test4 ${test4_source})
add_test(RunTest8Threads test4)

