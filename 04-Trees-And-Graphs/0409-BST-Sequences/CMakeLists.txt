add_library("0409-BST-Sequences" solution.cpp)

add_executable("0409-BST-Sequences_Test" solution_test.cpp)
target_link_libraries("0409-BST-Sequences_Test" PRIVATE "0409-BST-Sequences" GTest::gtest GTest::gtest_main)