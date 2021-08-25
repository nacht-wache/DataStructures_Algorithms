include_directories(../lib/googletest
    ${PROJECT_SOURCE_DIR}/alg_/common_alg)

add_executable(run_common_alg_tests
    LIS_tests.cpp)

target_link_libraries(run_common_alg_tests gtest gtest_main)
target_link_libraries(run_common_alg_tests ${COMMON_SORTING_ALG})