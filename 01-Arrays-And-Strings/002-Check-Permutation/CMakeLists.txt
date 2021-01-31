add_library("002-Check-Permutation" solution.cpp)

add_executable("002-Check-Permutation_Test" solution_test.cpp)
target_link_libraries("002-Check-Permutation_Test" PRIVATE "002-Check-Permutation" GTest::gtest GTest::gtest_main)