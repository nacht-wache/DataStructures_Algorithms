include_directories(${PROJECT_SOURCE_DIR}/lib/googletest
    ${PROJECT_SOURCE_DIR}/data_structures/ds_alg/)

add_executable(run_ds_course_tests
    stack_tests)

target_link_libraries(run_ds_course_tests gtest gtest_main)
target_link_libraries(run_ds_course_tests ds_course)