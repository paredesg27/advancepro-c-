cmake_minimum_required(VERSION 3.24)
project(paredesg1_h3)

set(CMAKE_CXX_STANDARD 17)

add_executable(paredesg1_h3 main.cpp Student.cpp Logger.cpp Logger.h Grade.cpp Grade.h Student.h)
