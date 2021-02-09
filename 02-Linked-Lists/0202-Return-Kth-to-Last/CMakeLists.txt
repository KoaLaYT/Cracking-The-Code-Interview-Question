add_library("0202-Return-Kth-to-Last" solution.cpp)

add_executable("0202-Return-Kth-to-Last_Test" solution_test.cpp)
target_link_libraries("0202-Return-Kth-to-Last_Test" PRIVATE "0202-Return-Kth-to-Last" GTest::gtest GTest::gtest_main)