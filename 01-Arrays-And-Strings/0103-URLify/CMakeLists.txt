add_library("0103-URLify" solution.cpp)

add_executable("0103-URLify_Test" solution_test.cpp)
target_link_libraries("0103-URLify_Test" PRIVATE "0103-URLify" GTest::gtest GTest::gtest_main)