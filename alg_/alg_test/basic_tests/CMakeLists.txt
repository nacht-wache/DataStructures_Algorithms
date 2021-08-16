include_directories(../lib/googletest
    ${PROJECT_SOURCE_DIR}/alg_/algms)

add_executable(run_basic_tests
    basic_check.cpp)

target_link_libraries(run_basic_tests gtest gtest_main)
target_link_libraries(run_basic_tests task)