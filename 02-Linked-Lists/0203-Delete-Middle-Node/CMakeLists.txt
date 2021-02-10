add_library("0203-Delete-Middle-Node" solution.cpp)

add_executable("0203-Delete-Middle-Node_Test" solution_test.cpp)
target_link_libraries("0203-Delete-Middle-Node_Test" PRIVATE "0203-Delete-Middle-Node" GTest::gtest GTest::gtest_main)