add_library("0306-Animal-Shelter" solution.cpp)

add_executable("0306-Animal-Shelter_Test" solution_test.cpp)
target_link_libraries("0306-Animal-Shelter_Test" PRIVATE "0306-Animal-Shelter" GTest::gtest GTest::gtest_main)