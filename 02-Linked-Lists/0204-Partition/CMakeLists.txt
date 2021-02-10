add_library("0204-Partition" solution.cpp)

add_executable("0204-Partition_Test" solution_test.cpp)
target_link_libraries("0204-Partition_Test" PRIVATE "0204-Partition" GTest::gtest GTest::gtest_main)