/*
 -------------------------------------------------------------------------------
    Copyright (C) 2015  Dirk Stolle

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 -------------------------------------------------------------------------------
*/

#include <chrono>
#include <iostream>
#include "../libmath/fibonacci.hpp"

int main()
{
  /* This program compares the computation times that are required to calculate
     the 46th Fibonacci number via three different methods.
  */
  std::cout << "Computation time comparison for calculation methods of Fibonacci numbers:" << std::endl;

  libmath::DefaultFibonacci fibo;

  const unsigned int n=45;
  //use iterative function
  const std::chrono::time_point<std::chrono::steady_clock> it_start = std::chrono::steady_clock::now();
  std::cout << "f("<<n<<") = " << fibo.iterative(n) << " (iterative)" << std::endl;
  const auto it_end = std::chrono::steady_clock::now();

  //recursive function (sloooooooooooow!)
  const auto rec_start = std::chrono::steady_clock::now();
  std::cout << "f("<<n<<") = " << fibo.recursive(n) << " (recursive)" << std::endl;
  const auto rec_end = std::chrono::steady_clock::now();

  //"fast" recursive function
  const auto rec_fast_start = std::chrono::steady_clock::now();
  std::cout << "f("<<n<<") = " << fibo.recursive_fast(n) << " (fast recursive)" << std::endl << std::endl;
  const auto rec_fast_end = std::chrono::steady_clock::now();

  const auto durationIterative = it_end - it_start;
  const auto durationRecursive = rec_end - rec_start;
  const auto durationRecursiveFast = rec_fast_end - rec_fast_start;

  std::cout << "Durations:" << std::endl
            << "Iterative: " << std::chrono::duration_cast<std::chrono::microseconds>(durationIterative).count() << " microseconds" << std::endl
            << "Recursive: " << std::chrono::duration_cast<std::chrono::microseconds>(durationRecursive).count() << " microseconds"
            << " (ca. " << std::chrono::duration_cast<std::chrono::seconds>(durationRecursive).count() << " seconds and "
            << std::chrono::duration_cast<std::chrono::milliseconds>(durationRecursive).count() % 1000 << " milliseconds)"
            << std::endl
            << "Recursive (shorthand): " << std::chrono::duration_cast<std::chrono::microseconds>(durationRecursiveFast).count() << " microseconds" << std::endl;

  return 0;
}
