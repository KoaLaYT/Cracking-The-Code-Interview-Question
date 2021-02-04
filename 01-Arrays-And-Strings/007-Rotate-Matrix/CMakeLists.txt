add_library("007-Rotate-Matrix" solution.cpp)

add_executable("007-Rotate-Matrix_Test" solution_test.cpp)
target_link_libraries("007-Rotate-Matrix_Test" PRIVATE "007-Rotate-Matrix" GTest::gtest GTest::gtest_main)