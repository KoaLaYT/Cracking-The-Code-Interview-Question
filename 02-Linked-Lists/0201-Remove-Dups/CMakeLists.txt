add_library("0201-Remove-Dups" solution.cpp)

add_executable("0201-Remove-Dups_Test" solution_test.cpp)
target_link_libraries("0201-Remove-Dups_Test" PRIVATE "0201-Remove-Dups" GTest::gtest GTest::gtest_main)