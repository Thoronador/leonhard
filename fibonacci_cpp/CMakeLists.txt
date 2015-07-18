# We might support earlier versions, too, but it's only tested with 2.8.9.
cmake_minimum_required (VERSION 2.8)

project(fibonacci_comparison)

set(fibo_comp_sources
    ../libmath/fibonacci.hpp
    main.cpp)

add_definitions(-std=c++0x)
if (CMAKE_COMPILER_IS_GNUCC)
    add_definitions(-Wall -O3 -fexceptions)
endif (CMAKE_COMPILER_IS_GNUCC)

set( CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -s" )

add_executable(fibonacci_comparison ${fibo_comp_sources})
