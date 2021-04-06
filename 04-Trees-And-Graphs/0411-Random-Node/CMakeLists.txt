add_library("0411-Random-Node" solution.cpp)

add_executable("0411-Random-Node_Test" solution_test.cpp)
target_link_libraries("0411-Random-Node_Test" PRIVATE "0411-Random-Node" GTest::gtest GTest::gtest_main)