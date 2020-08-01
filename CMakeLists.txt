# binary-patch
cmake_minimum_required(VERSION 3.13)
project("binary-patch")


enable_testing()


# Internal modules
add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/binary-patch/defaults")
add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/binary-patch/example")


# External modules
add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/external/rapidcsv")
