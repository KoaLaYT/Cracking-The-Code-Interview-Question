add_library("0206-Palindrome" solution.cpp)

add_executable("0206-Palindrome_Test" solution_test.cpp)
target_link_libraries("0206-Palindrome_Test" PRIVATE "0206-Palindrome" GTest::gtest GTest::gtest_main)