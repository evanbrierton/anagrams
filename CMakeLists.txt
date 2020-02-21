cmake_minimum_required(VERSION 3.15)
project(assignment1 C)

set(CMAKE_C_STANDARD 99)

add_executable(assignment1 main.c io.c sort.c anagrams.c utils.c)
configure_file(input.txt ${CMAKE_BINARY_DIR} COPYONLY)