add_library("0303-Stack-Of-Plates" solution.cpp)

add_executable("0303-Stack-Of-Plates_Test" solution_test.cpp)
target_link_libraries("0303-Stack-Of-Plates_Test" PRIVATE "0303-Stack-Of-Plates" GTest::gtest GTest::gtest_main)