add_library("0408-First-Common-Ancestor" solution.cpp)

add_executable("0408-First-Common-Ancestor_Test" solution_test.cpp)
target_link_libraries("0408-First-Common-Ancestor_Test" PRIVATE "0408-First-Common-Ancestor" GTest::gtest GTest::gtest_main)