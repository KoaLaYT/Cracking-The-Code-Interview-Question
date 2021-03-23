add_library("0402-Minimal-Tree" solution.cpp)

add_executable("0402-Minimal-Tree_Test" solution_test.cpp)
target_link_libraries("0402-Minimal-Tree_Test" PRIVATE "0402-Minimal-Tree" GTest::gtest GTest::gtest_main)