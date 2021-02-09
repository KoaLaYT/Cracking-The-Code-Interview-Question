add_library("0101-Is-Unique" solution.cpp)

add_executable("0101-Is-Unique_Test" solution_test.cpp)
target_link_libraries("0101-Is-Unique_Test" PRIVATE "0101-Is-Unique" GTest::gtest GTest::gtest_main)