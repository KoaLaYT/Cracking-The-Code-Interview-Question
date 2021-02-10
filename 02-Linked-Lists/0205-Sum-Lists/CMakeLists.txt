add_library("0205-Sum-Lists" solution.cpp)

add_executable("0205-Sum-Lists_Test" solution_test.cpp)
target_link_libraries("0205-Sum-Lists_Test" PRIVATE "0205-Sum-Lists" GTest::gtest GTest::gtest_main)