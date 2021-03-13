add_library("Red-Black-Tree" solution.cpp)

add_executable("Red-Black-Tree_Test" solution_test.cpp)
target_link_libraries("Red-Black-Tree_Test" PRIVATE "Red-Black-Tree" GTest::gtest GTest::gtest_main)