add_library("Binary-Search-Tree" solution.cpp)

add_executable("Binary-Search-Tree_Test" solution_test.cpp)
target_link_libraries("Binary-Search-Tree_Test" PRIVATE "Binary-Search-Tree" GTest::gtest GTest::gtest_main)