add_library("0406-Successor" solution.cpp)

add_executable("0406-Successor_Test" solution_test.cpp)
target_link_libraries("0406-Successor_Test" PRIVATE "0406-Successor" GTest::gtest GTest::gtest_main)