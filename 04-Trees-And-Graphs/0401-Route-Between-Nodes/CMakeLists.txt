add_library("0401-Route-Between-Nodes" solution.cpp)

add_executable("0401-Route-Between-Nodes_Test" solution_test.cpp)
target_link_libraries("0401-Route-Between-Nodes_Test" PRIVATE "0401-Route-Between-Nodes" GTest::gtest GTest::gtest_main)