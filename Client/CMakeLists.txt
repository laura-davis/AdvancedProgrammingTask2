cmake_minimum_required(VERSION 3.20)
project(Simple-Server-and-Chat-Program)

set(CMAKE_CXX_STANDARD 14)

add_executable(Client
        Client.cpp
        Client.h
        Comms.cpp
        Comms.h
        Exception.h
        main.cpp
        Server.cpp
        Server.h
        Toggle.h)