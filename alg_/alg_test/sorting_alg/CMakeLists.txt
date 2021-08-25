include_directories(../lib/googletest
    ${PROJECT_SOURCE_DIR}/alg_/sorting_alg)

add_executable(run_sorting_tests
    sorting_tests.cpp)

target_link_libraries(run_sorting_tests gtest gtest_main)
target_link_libraries(run_sorting_tests sorting_alg)