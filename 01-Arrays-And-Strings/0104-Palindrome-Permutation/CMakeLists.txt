add_library("0104-Palindrome-Permutation" solution.cpp)

add_executable("0104-Palindrome-Permutation_Test" solution_test.cpp)
target_link_libraries("0104-Palindrome-Permutation_Test" PRIVATE "0104-Palindrome-Permutation" GTest::gtest GTest::gtest_main)