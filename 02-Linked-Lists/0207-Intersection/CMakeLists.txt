add_library("0207-Intersection" solution.cpp)

add_executable("0207-Intersection_Test" solution_test.cpp)
target_link_libraries("0207-Intersection_Test" PRIVATE "0207-Intersection" GTest::gtest GTest::gtest_main)