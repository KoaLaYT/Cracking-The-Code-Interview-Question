add_library("009-String-Rotation" solution.cpp)

add_executable("009-String-Rotation_Test" solution_test.cpp)
target_link_libraries("009-String-Rotation_Test" PRIVATE "009-String-Rotation" GTest::gtest GTest::gtest_main)