cmake_minimum_required(VERSION 3.13)
project(CPPAssignment)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CPPAssignment
        cg.hpp
        heat.hpp
        main.cpp
        matrix.hpp
        vector.hpp)
