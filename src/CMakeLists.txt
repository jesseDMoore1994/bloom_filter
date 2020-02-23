project(bloom_filter)
add_library(dicReader_lib STATIC dicReader.cpp dicReader.hpp)
add_library(bloomFilter_lib STATIC bloomFilter.cpp bloomFilter.hpp)
target_include_directories(dicReader_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(bloomFilter_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(bloom_filter main.cpp)
target_link_libraries(bloom_filter PRIVATE dicReader_lib bloomFilter_lib)
