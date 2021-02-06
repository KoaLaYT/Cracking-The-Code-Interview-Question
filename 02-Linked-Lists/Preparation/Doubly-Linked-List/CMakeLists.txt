add_library("Doubly-Linked-List" solution.cpp)

add_executable("Doubly-Linked-List_Test" solution_test.cpp)
target_link_libraries("Doubly-Linked-List_Test" PRIVATE "Doubly-Linked-List" GTest::gtest GTest::gtest_main)