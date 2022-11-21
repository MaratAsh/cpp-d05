cmake_minimum_required(VERSION 3.21)
project(cpp_d05)

set(CMAKE_CXX_STANDARD 98)

add_executable(cpp_05_00
        ex00/srcs/Bureaucrat.cpp
        ex00/srcs/main.cpp

        ex00/includes/Bureaucrat.hpp
        )

target_include_directories(cpp_05_00 PRIVATE ex00/includes/)

add_executable(cpp_05_01
        ex01/srcs/Bureaucrat.cpp
        ex01/srcs/Form.cpp
        ex01/srcs/main.cpp

        ex01/includes/Bureaucrat.hpp
        ex01/includes/Form.hpp
        )

target_include_directories(cpp_05_01 PRIVATE ex01/includes/)

add_executable(cpp_05_02
        ex02/srcs/Bureaucrat.cpp
        ex02/srcs/AForm.cpp
        ex02/srcs/main.cpp
        ex02/srcs/PresidentialPardonForm.cpp
        ex02/srcs/RobotomyRequestForm.cpp
        ex02/srcs/ShrubberyCreationForm.cpp

        ex02/includes/Bureaucrat.hpp
        ex02/includes/AForm.hpp
        ex02/includes/PresidentialPardonForm.hpp
        ex02/includes/RobotomyRequestForm.hpp
        ex02/includes/ShrubberyCreationForm.hpp
        )

target_include_directories(cpp_05_02 PRIVATE ex02/includes/)
