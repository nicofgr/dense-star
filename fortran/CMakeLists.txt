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

add_executable(Fig44and45_P3.out src/fig44and45/P3estrelas_ultrarel2.f90)
add_executable(Fig44and45_P4.out src/fig44and45/P4estrelas_relativ2.f90)

add_executable(Fig46_B1.out src/fig46/P4estrelas_relativ2_B1.f90)
add_executable(Fig46_B2.out src/fig46/P4estrelas_relativ2_B2.f90)
add_executable(Fig46_B3.out src/fig46/P4estrelas_relativ2_B3.f90)
add_executable(Fig46_B4.out src/fig46/P4estrelas_relativ2_B4.f90)

add_executable(Fig47and48_P5.out src/fig47and48/P5.f90)
add_executable(Fig47and48_P1.out src/fig47and48/P1.f90)
