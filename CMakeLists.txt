cmake_minimum_required(VERSION 3.20)
project(AdvancedProgrammingTask2)

set(CMAKE_CXX_STANDARD 14)

add_library(exception Exception.cpp)
add_executable(client Client.cpp)
add_executable(server Server.cpp)
target_link_libraries(server exception)
target_link_libraries(client exception)