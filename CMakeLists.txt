cmake_minimum_required(VERSION 3.28)
project(Tables)

add_subdirectory(./libs/Tables)

add_library(libLRModel ./src/LRModel.cpp)
target_include_directories(libLRModel PUBLIC ./include PRIVATE ./src)
target_link_libraries(libLRModel libTables)

add_executable(testLRModel ./tests/Main.cpp)
target_link_libraries(testLRModel libLRModel)
