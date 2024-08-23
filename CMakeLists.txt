cmake_minimum_required(VERSION 3.28)
project(untitled12 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled12
        src/alert.c
        src/main.c
        src/utils.c
        src/contact.c
        include/contact.h
        include/alert.h
        include/utils.h)
