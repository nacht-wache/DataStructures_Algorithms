cmake_minimum_required(VERSION 3.10)

project(DS_alg)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "--std=c++17 -O0")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_GLIBCXX_DEBUG")

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(alg_)
add_subdirectory(data_structures)
add_subdirectory(lib/googletest)

target_include_directories(${PROJECT_NAME}
        PUBLIC alg_/common_alg
        PUBLIC alg_/sorting_alg
        PUBLIC data_structures/heap
        )

execute_process(COMMAND conan install ${CMAKE_SOURCE_DIR} --build missing)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

target_link_libraries(${PROJECT_NAME}
        PRIVATE HEAP CONAN_PKG::boost)



