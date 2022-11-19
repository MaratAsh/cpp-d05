cmake_minimum_required(VERSION 3.21)
project(cpp_d05)

set(CMAKE_CXX_STANDARD 98)

add_executable(cpp_05_00
        ex00/srcs/Bureaucrat.cpp
        ex00/srcs/main.cpp

        ex00/includes/Bureaucrat.hpp
        )

target_include_directories(cpp_05_00 PRIVATE ex00/includes/)
