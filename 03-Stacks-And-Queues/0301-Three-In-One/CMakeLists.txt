add_library("0301-Three-In-One" solution.cpp)

add_executable("0301-Three-In-One_Test" solution_test.cpp)
target_link_libraries("0301-Three-In-One_Test" PRIVATE "0301-Three-In-One" GTest::gtest GTest::gtest_main)