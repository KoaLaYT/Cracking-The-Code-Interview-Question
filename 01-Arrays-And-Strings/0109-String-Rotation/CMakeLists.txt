add_library("0109-String-Rotation" solution.cpp)

add_executable("0109-String-Rotation_Test" solution_test.cpp)
target_link_libraries("0109-String-Rotation_Test" PRIVATE "0109-String-Rotation" GTest::gtest GTest::gtest_main)