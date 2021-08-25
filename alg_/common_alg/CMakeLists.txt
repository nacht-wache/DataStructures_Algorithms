
set(${COMMON_SORTING_ALG}
    LIS_nlogn)

add_library(LIS_nlogn LIS_nlogn.cpp)

include_directories(${PROJECT_SOURCE_DIR}/alg_/common_alg)
