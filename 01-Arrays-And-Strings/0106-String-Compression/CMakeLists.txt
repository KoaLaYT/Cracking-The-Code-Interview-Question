add_library("0106-String-Compression" solution.cpp)

add_executable("0106-String-Compression_Test" solution_test.cpp)
target_link_libraries("0106-String-Compression_Test" PRIVATE "0106-String-Compression" GTest::gtest GTest::gtest_main)