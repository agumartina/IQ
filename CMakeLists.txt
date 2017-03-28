cmake_minimum_required(VERSION 3.6)
project(IQ)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c structures.h dataN1_header.c dataN1_read.c libs/list.c)
add_executable(IQ ${SOURCE_FILES})