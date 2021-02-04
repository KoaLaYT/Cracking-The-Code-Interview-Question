add_library("008-Zero-Matrix" solution.cpp)

add_executable("008-Zero-Matrix_Test" solution_test.cpp)
target_link_libraries("008-Zero-Matrix_Test" PRIVATE "008-Zero-Matrix" GTest::gtest GTest::gtest_main)