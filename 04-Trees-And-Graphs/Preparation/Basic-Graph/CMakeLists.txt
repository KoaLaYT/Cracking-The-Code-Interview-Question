add_library("Basic-Graph" solution.cpp)

add_executable("Basic-Graph_Test" solution_test.cpp)
target_link_libraries("Basic-Graph_Test" PRIVATE "Basic-Graph" GTest::gtest GTest::gtest_main)