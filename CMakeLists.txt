cmake_minimum_required(VERSION 3.10)

project(test)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(alg_)

target_include_directories(${PROJECT_NAME} PUBLIC alg_/algms)

target_link_directories(${PROJECT_NAME} PRIVATE algms)

target_link_libraries(${PROJECT_NAME} PUBLIC task)



