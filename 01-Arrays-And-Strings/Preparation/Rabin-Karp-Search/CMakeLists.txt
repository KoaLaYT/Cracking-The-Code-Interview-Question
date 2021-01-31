add_library("Rabin-Karp-Search" solution.cpp)

add_executable("Rabin-Karp-Search_Test" solution_test.cpp)
target_link_libraries("Rabin-Karp-Search_Test" PRIVATE "Rabin-Karp-Search" GTest::gtest GTest::gtest_main)