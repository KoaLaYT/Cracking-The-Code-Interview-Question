add_library("001-Is-Unique" solution.cpp)

add_executable("001-Is-Unique_Test" solution_test.cpp)
target_link_libraries("001-Is-Unique_Test" PRIVATE "001-Is-Unique" GTest::gtest GTest::gtest_main)