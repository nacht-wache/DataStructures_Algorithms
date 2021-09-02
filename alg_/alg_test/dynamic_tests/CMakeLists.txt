include_directories(${PROJECT_SOURCE_DIR}/lib/googletest
    ${PROJECT_SOURCE_DIR}/alg_/dynamic)

add_executable(run_dynamic_tests
    calculator_tests.cpp)

target_link_libraries(run_dynamic_tests gtest gtest_main)
target_link_libraries(run_dynamic_tests dynamic)