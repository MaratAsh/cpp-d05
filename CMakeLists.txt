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


add_executable(cpp_05_03
        ex03/srcs/Bureaucrat.cpp
        ex03/srcs/AForm.cpp
        ex03/srcs/main.cpp
        ex03/srcs/PresidentialPardonForm.cpp
        ex03/srcs/RobotomyRequestForm.cpp
        ex03/srcs/ShrubberyCreationForm.cpp
        ex03/srcs/Intern.cpp

        ex03/includes/Bureaucrat.hpp
        ex03/includes/AForm.hpp
        ex03/includes/PresidentialPardonForm.hpp
        ex03/includes/RobotomyRequestForm.hpp
        ex03/includes/ShrubberyCreationForm.hpp
        ex03/includes/Intern.hpp
        )

target_include_directories(cpp_05_03 PRIVATE ex03/includes/)
