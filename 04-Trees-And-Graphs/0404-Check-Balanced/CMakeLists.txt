add_library("0404-Check-Balanced" solution.cpp)

add_executable("0404-Check-Balanced_Test" solution_test.cpp)
target_link_libraries("0404-Check-Balanced_Test" PRIVATE "0404-Check-Balanced" GTest::gtest GTest::gtest_main)