add_library("003-URLify" solution.cpp)

add_executable("003-URLify_Test" solution_test.cpp)
target_link_libraries("003-URLify_Test" PRIVATE "003-URLify" GTest::gtest GTest::gtest_main)