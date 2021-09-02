include_directories(${PROJECT_SOURCE_DIR}/lib/googletest
    ${PROJECT_SOURCE_DIR}/alg_/greedy)

add_executable(run_greedy_tests
    cookies_I_tests.cpp)

target_link_libraries(run_greedy_tests gtest gtest_main)
target_link_libraries(run_greedy_tests dynamic)