cmake_minimum_required(VERSION 3.27)
project(string C)

set(CMAKE_C_STANDARD 11)

add_executable(string main.c
        String/tasks/string.h
        String/tasks/string.c
        String/tasks/string_.h
        String/tasks/string_.c)
