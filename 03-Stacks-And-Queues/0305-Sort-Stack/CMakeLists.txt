add_library("0305-Sort-Stack" solution.cpp)

add_executable("0305-Sort-Stack_Test" solution_test.cpp)
target_link_libraries("0305-Sort-Stack_Test" PRIVATE "0305-Sort-Stack" GTest::gtest GTest::gtest_main)