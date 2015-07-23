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
#include "../../libmath/prime.hpp"

int main()
{
  const uint64_t number = 600851475143;
  std::cout << "Calculating prime factors of " << number << "..." << std::endl;
  auto pf = libmath::PrimeFactors<uint64_t>::compute(number);
  auto iter = pf.begin();
  while (iter != pf.end())
  {
    std::cout << iter->prime << "**" << iter->exponent << std::endl;
    ++iter;
  } //while

  std::cout << "The largest prime factor of " << number << " is " << pf.rbegin()->prime << ".\n";
  return 0;
}
