include_directories(${PROJECT_SOURCE_DIR}/lib/googletest
    ${PROJECT_SOURCE_DIR}/data_structures/heap)

add_executable(run_ds_tests
    max_heap_tests.cpp ../../heap/test1.txt)

target_link_libraries(run_ds_tests gtest gtest_main)
target_link_libraries(run_ds_tests HEAP)