add_library("0107-Rotate-Matrix" solution.cpp)

add_executable("0107-Rotate-Matrix_Test" solution_test.cpp)
target_link_libraries("0107-Rotate-Matrix_Test" PRIVATE "0107-Rotate-Matrix" GTest::gtest GTest::gtest_main)