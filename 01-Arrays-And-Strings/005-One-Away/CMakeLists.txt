add_library("005-One-Away" solution.cpp)

add_executable("005-One-Away_Test" solution_test.cpp)
target_link_libraries("005-One-Away_Test" PRIVATE "005-One-Away" GTest::gtest GTest::gtest_main)