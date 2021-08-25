cmake_minimum_required(VERSION 3.10)

project(program)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "--std=c++17")

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(alg_)

target_include_directories(${PROJECT_NAME}
    PUBLIC alg_/common_alg
    PUBLIC alg_/sorting_alg)


target_link_libraries(${PROJECT_NAME} PUBLIC ${COMMON_SORTING_ALG})



