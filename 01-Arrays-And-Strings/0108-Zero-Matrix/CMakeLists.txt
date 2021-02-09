add_library("0108-Zero-Matrix" solution.cpp)

add_executable("0108-Zero-Matrix_Test" solution_test.cpp)
target_link_libraries("0108-Zero-Matrix_Test" PRIVATE "0108-Zero-Matrix" GTest::gtest GTest::gtest_main)