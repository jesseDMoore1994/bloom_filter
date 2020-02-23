cmake_minimum_required(VERSION 3.5.1)

project(bloom_filter)

# lots of warnings and all warnings as errors
add_compile_options(-Wall -Wextra -pedantic -Werror)

add_subdirectory(external/Catch2)
add_subdirectory(src)
add_subdirectory(tests)

enable_testing()
add_test(test_bloom_filter tests/tests)
