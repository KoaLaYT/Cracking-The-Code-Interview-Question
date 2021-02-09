add_library("0105-One-Away" solution.cpp)

add_executable("0105-One-Away_Test" solution_test.cpp)
target_link_libraries("0105-One-Away_Test" PRIVATE "0105-One-Away" GTest::gtest GTest::gtest_main)