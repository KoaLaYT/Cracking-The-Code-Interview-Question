add_library("0403-List-of-Depths" solution.cpp)

add_executable("0403-List-of-Depths_Test" solution_test.cpp)
target_link_libraries("0403-List-of-Depths_Test" PRIVATE "0403-List-of-Depths" GTest::gtest GTest::gtest_main)