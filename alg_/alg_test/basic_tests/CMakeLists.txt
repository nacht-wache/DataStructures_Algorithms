include_directories(../lib/googletest)

add_executable(run_basic_tests
    basic_check.cpp)

target_link_libraries(run_basic_tests gtest gtest_main)
target_link_libraries(run_basic_tests task)