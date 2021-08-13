cmake_minimum_required(VERSION 3.20)
project(AdvancedProgrammingTask2)

set(CMAKE_CXX_STANDARD 14)

add_executable(AdvancedProgrammingTask2
        Client.h
        Client.cpp
        Server.h
        Server.cpp
        Comms.cpp
        Comms.h
        Exceptions.h
        Exceptions.cpp
        Toggle.h
        Toggle.cpp)
