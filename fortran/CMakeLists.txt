cmake_minimum_required(VERSION 3.9.1)

project(DenseStarFortran)
enable_language(Fortran)

set(FVERSION "-std=gnu")
set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} ${FVERSION} -fdefault-real-8 -fdefault-double-8")

set(EXECUTABLE_OUTPUT_PATH ../output/)

#set(SOURCES P1estrelas_ultrarel.f90)

#add_executable(Fig43_P1.out ${SOURCES})
add_executable(Fig43_P1.out src/fig43/P1estrelas_ultrarel.f90)
add_executable(Fig43_P2.out src/fig43/P2estrelas_relativ.f90)
