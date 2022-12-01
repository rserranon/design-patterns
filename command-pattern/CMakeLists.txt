cmake_minimum_required(VERSION 3.16)
project(command-pattern)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG  "-g")
# run with > cmake -DCMAKE_BUILD_TYPE=Debug

include_directories(.)

add_executable(command-pattern
        main.cpp
        command.h
        command.cpp
        commandmanager.h
        character.h)
