cmake_minimum_required(VERSION 3.19)

# My vcpkg root dir
set(ENV{VCPKG_ROOT} "/Users/koalayt")
set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/vcpkg/scripts/buildsystems/vcpkg.cmake"
    CACHE STRING "")

project(Cracking_The_Code_Interview_Questions)

set(CMAKE_CXX_STANDARD 17)

find_package(GTest CONFIG REQUIRED)

add_subdirectory("01-Arrays-And-Strings")