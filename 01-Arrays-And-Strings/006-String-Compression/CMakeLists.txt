add_library("006-String-Compression" solution.cpp)

add_executable("006-String-Compression_Test" solution_test.cpp)
target_link_libraries("006-String-Compression_Test" PRIVATE "006-String-Compression" GTest::gtest GTest::gtest_main)