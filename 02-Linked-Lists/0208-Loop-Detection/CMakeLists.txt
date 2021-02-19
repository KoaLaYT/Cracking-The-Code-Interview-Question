add_library("0208-Loop-Detection" solution.cpp)

add_executable("0208-Loop-Detection_Test" solution_test.cpp)
target_link_libraries("0208-Loop-Detection_Test" PRIVATE "0208-Loop-Detection" GTest::gtest GTest::gtest_main)