project(bloom_filter_tests)

add_executable(tests test_dicReader.cpp test_bloomFilter.cpp)
target_link_libraries(tests PRIVATE dicReader_lib bloomFilter_lib Catch2)
FILE(COPY example_dictionary.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
