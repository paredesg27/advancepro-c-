cmake_minimum_required(VERSION 3.24)
project(HospitalAdmin)

set(CMAKE_CXX_STANDARD 17)

add_executable(HospitalAdmin main.cpp HospitalAdmin.h HospitalAdmin.cpp NurseandDoctor.h NurseandDoctor.cpp Logger.h Logger.cpp)
