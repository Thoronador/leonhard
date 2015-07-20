cmake_minimum_required (VERSION 2.8)
# Recurse into subdirectory for Fortran CMake test.
add_subdirectory (cmake_test)

# Recurse into subdirectory for problem 1.
add_subdirectory (p001_multiples_of_3_and_5)

# Recurse into subdirectory for problem 2.
add_subdirectory (p002_even_fibonacci_numbers)

# Recurse into subdirectory for some more Fibonacci stuff in C++.
add_subdirectory (fibonacci_cpp)

# Recurse into subdirectory for problem 3.
add_subdirectory (p003_largest_prime_factor)

# Recurse into subdirectory for problem 14.
add_subdirectory (p014_longest_collatz_sequence)
