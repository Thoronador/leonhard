cmake_minimum_required (VERSION 2.8)
# Recurse into subdirectory for Fortran CMake test.
add_subdirectory (cmake_test)

# Recurse into subdirectory for problems.
add_subdirectory (pxxx)

# Recurse into subdirectory for some more Fibonacci stuff in C++.
add_subdirectory (fibonacci_cpp)
