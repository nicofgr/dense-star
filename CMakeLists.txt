cmake_minimum_required(VERSION 3.9.1)

project(DenseStar)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(EXECUTABLE_OUTPUT_PATH ../output/)
set(SOURCES main.cpp 
            src/dense-star.cpp 
            include/dense-star.hpp)

add_executable(dense_star.out ${SOURCES})