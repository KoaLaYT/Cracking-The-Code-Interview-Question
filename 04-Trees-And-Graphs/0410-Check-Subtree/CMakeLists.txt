add_library("0410-Check-Subtree" solution.cpp)

add_executable("0410-Check-Subtree_Test" solution_test.cpp)
target_link_libraries("0410-Check-Subtree_Test" PRIVATE "0410-Check-Subtree" GTest::gtest GTest::gtest_main)