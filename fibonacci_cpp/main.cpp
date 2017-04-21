/*
 -------------------------------------------------------------------------------
    Program to compute a Fibonacci number via different methods.
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

#include <algorithm>
#include <chrono>
#include <iostream>
#include <sstream>
#include "../libmath/fibonacci.hpp"

const int rcInvalidParameter = 1;


void showHelp()
{
  std::cout << "fibonacci [-R | --recursive] [index]\n"
            << "\n"
            << "options:\n"
            << "  --help        - displays this help message and quits\n"
            << "  -?            - same as --help\n"
            << "  --version     - displays the version of the program and quits\n"
            << "  index         - non-negative integer number that indicates the zero-based\n"
            << "                  index of the Fibonacci number which shall be computed.\n"
            << "                  The \"zeroth\" number is 0, the first is 1, the second is 1,\n"
            << "                  the third is 2, the fourth is 3, and so on.\n"
            << "                  Default index is 45.\n"
            << "  --recursive   - use slow recursive method, too. This is very(!) slow,\n"
            << "                  especially for indexes above 40.\n"
            << "  -R | -r       - same as --recursive\n";
}

void showVersion()
{
  std::cout << "Compute Fibonacci numbers, version 1.0, 2015-07-19\n";
}

int main(int argc, char **argv)
{
  /* This program compares the computation times that are required to calculate
     the 46th Fibonacci number via several different methods.
  */

  bool doRecursive = false;
  bool useCustomN = false;
  unsigned int custom_n = 0;

  if (argc>1 and argv!=NULL)
  {
    int i=1;
    while (i < argc)
    {
      if (argv[i] != NULL)
      {
        const std::string param = std::string(argv[i]);
        if (param == "--help" or param == "-?")
        {
          showHelp();
          return 0;
        }//if help wanted
        //version information requested?
        else if (param == "--version")
        {
          showVersion();
          return 0;
        }
        //recursive variant requested
        else if ((param == "-R") or (param == "-r") or (param == "--recursive"))
        {
          if (!doRecursive)
          {
            //enable slow recursive variant
            doRecursive = true;
          }
          else
          {
            std::cout << "Error: \"" << param<<"\" must not be specified more than once.\n";
            return rcInvalidParameter;
          }
        }//recursive option

        else if (std::all_of(param.cbegin(), param.cend(), [](const char c) { return std::isdigit(c);} ))
        {
          if (useCustomN)
          {
            std::cout << "Error: You already have set the value of n to "
                      << custom_n << ".\n";
            return rcInvalidParameter;
          }
          std::istringstream stream(param);
          stream >> custom_n;
          useCustomN = true;
        }//specific value of n
        else
        {
          //unknown or wrong parameter
          std::cout << "Invalid parameter given: \"" << param << "\".\n"
                    /*<< "Use --help to get a list of valid parameters.\n"*/;
          return rcInvalidParameter;
        }

      }//parameter exists
      else
      {
        std::cout << "Parameter at index " << i << " is NULL.\n";
        return rcInvalidParameter;
      }
      ++i;//on to next parameter
    }//while
  }//if argc

  std::cout << "Computation time comparison for calculation methods of Fibonacci numbers:" << std::endl;

  libmath::DefaultFibonacci fibo;

  const unsigned int n = useCustomN ? custom_n : 45;
  //use iterative function
  const std::chrono::time_point<std::chrono::steady_clock> it_start = std::chrono::steady_clock::now();
  const uint64_t iterative = fibo.iterative(n);
  const auto it_end = std::chrono::steady_clock::now();
  std::cout << "f("<<n<<") = " << iterative << " (iterative)" << std::endl
            << "\tDuration: " << std::chrono::duration_cast<std::chrono::microseconds>(it_end - it_start).count()
            << " microsecond(s)" << std::endl;

  //recursive function (sloooooooooooow!)
  if (doRecursive)
  {
    const auto rec_start = std::chrono::steady_clock::now();
    const uint64_t recursive = fibo.recursive(n);
    const auto rec_end = std::chrono::steady_clock::now();
    std::cout << "f("<<n<<") = " << recursive << " (recursive)" << std::endl
              << "\tDuration: " << std::chrono::duration_cast<std::chrono::microseconds>(rec_end - rec_start).count()
              << " microseconds" << std::endl;
  }

  //"fast" recursive function, still slow with indexes above 350
  const auto rec_fast_start = std::chrono::steady_clock::now();
  const uint64_t recursive_fast = fibo.recursive_fast(n);
  const auto rec_fast_end = std::chrono::steady_clock::now();
  std::cout << "f("<<n<<") = " << recursive_fast << " (fast recursive)" << std::endl
            << "\tDuration: " << std::chrono::duration_cast<std::chrono::microseconds>(rec_fast_end - rec_fast_start).count()
            << " microseconds" << std::endl;

  //formula of Moivre and Binet - fast, but might be less precise
  // -> it also gives incorrect values for the first few indexes, and above ca. 100
  const auto moivre_start = std::chrono::steady_clock::now();
  const uint64_t moivre = fibo.direct(n);
  const auto moivre_end = std::chrono::steady_clock::now();
  std::cout << "f("<<n<<") = " << moivre << " (Moivre/Binet)" << std::endl
            << "\tDuration: " << std::chrono::duration_cast<std::chrono::microseconds>(moivre_end - moivre_start).count() << " microseconds" << std::endl;

  return 0;
}
