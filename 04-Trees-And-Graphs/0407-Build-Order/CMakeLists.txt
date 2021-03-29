add_library("0407-Build-Order" solution.cpp)

add_executable("0407-Build-Order_Test" solution_test.cpp)
target_link_libraries("0407-Build-Order_Test" PRIVATE "0407-Build-Order" GTest::gtest GTest::gtest_main)