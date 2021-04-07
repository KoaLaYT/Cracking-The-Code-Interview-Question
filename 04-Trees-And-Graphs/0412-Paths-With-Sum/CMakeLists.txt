add_library("0412-Paths-With-Sum" solution.cpp)

add_executable("0412-Paths-With-Sum_Test" solution_test.cpp)
target_link_libraries("0412-Paths-With-Sum_Test" PRIVATE "0412-Paths-With-Sum" GTest::gtest GTest::gtest_main)