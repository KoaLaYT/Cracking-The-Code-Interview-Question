add_library("0102-Check-Permutation" solution.cpp)

add_executable("0102-Check-Permutation_Test" solution_test.cpp)
target_link_libraries("0102-Check-Permutation_Test" PRIVATE "0102-Check-Permutation" GTest::gtest GTest::gtest_main)