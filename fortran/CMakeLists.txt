cmake_minimum_required(VERSION 3.9.1)

project(DenseStarFortran)
enable_language(Fortran)

set(FVERSION "-std=gnu")
set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} ${FVERSION}")

set(EXECUTABLE_OUTPUT_PATH ../output/)

set(SOURCES P1estrelas_ultrarel.f90)

add_executable(P1estrelas.out ${SOURCES})
