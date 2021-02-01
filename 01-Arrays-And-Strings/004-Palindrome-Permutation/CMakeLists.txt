add_library("004-Palindrome-Permutation" solution.cpp)

add_executable("004-Palindrome-Permutation_Test" solution_test.cpp)
target_link_libraries("004-Palindrome-Permutation_Test" PRIVATE "004-Palindrome-Permutation" GTest::gtest GTest::gtest_main)