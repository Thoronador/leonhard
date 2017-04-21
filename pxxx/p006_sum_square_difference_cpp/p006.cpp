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

#include <cstdint>
#include <iostream>

int main()
{
  const int_fast64_t limit = 100;
  int_fast64_t i;

  int_fast64_t sum_of_squares = 0;
  int_fast64_t sum = 0;

  for (i = 1; i <= limit; ++i)
  {
    sum_of_squares += i*i;
    sum += i;
  } //for i

  const int_fast64_t square_of_sum = sum * sum;
  std::cout << "Sum of squares of the " << limit << " natural numbers: "
            << sum_of_squares << std::endl << "Square of sum: "
            << square_of_sum << std::endl
            << "Difference is " << (square_of_sum-sum_of_squares) << std::endl;
  return 0;
}
