add_library("0405-Validate-BST" solution.cpp)

add_executable("0405-Validate-BST_Test" solution_test.cpp)
target_link_libraries("0405-Validate-BST_Test" PRIVATE "0405-Validate-BST" GTest::gtest GTest::gtest_main)