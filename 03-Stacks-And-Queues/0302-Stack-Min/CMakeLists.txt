add_library("0302-Stack-Min" solution.cpp)

add_executable("0302-Stack-Min_Test" solution_test.cpp)
target_link_libraries("0302-Stack-Min_Test" PRIVATE "0302-Stack-Min" GTest::gtest GTest::gtest_main)