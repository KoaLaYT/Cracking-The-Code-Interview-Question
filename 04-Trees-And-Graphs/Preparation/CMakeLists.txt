add_subdirectory("Binary-Search-Tree")
add_subdirectory("Red-Black-Tree")

add_executable("Tree-Experiment" tree_experiment.cpp)
target_link_libraries("Tree-Experiment" PRIVATE "Binary-Search-Tree" "Red-Black-Tree")