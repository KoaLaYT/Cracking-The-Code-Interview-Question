add_library("0304-Queue-Via-Stack" solution.cpp)

add_executable("0304-Queue-Via-Stack_Test" solution_test.cpp)
target_link_libraries("0304-Queue-Via-Stack_Test" PRIVATE "0304-Queue-Via-Stack" GTest::gtest GTest::gtest_main)