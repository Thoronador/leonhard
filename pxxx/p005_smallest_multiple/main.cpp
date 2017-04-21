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

template<typename T>
void show(const std::vector<libmath::PrimeFactor<T> >& factors)
{
  for(auto&& it: factors)
  {
    std::cout << it.prime << "**" << it.exponent << std::endl;
  } //for
}

int main()
{
  std::vector<libmath::PrimeFactor<uint_least64_t> > factors_current;
  std::vector<libmath::PrimeFactor<uint_least64_t> > factors_max = libmath::PrimeFactors<uint_least64_t>::compute(2);

  uint_least64_t i = 0;
  for (i = 1; i <= 20; ++i)
  {
    std::cout << "i: " << i << std::endl;
    factors_current = libmath::PrimeFactors<uint_least64_t>::compute(i);
    factors_max = libmath::PrimeFactors<uint_least64_t>::max(factors_current, factors_max);
    std::cout << "Current: " << std::endl;
    show(factors_current);
    std::cout << "Max: " << std::endl;
    show(factors_max);
    std::cout << std::endl;
  } //for

  show(factors_max);
  std::cout << "Product: " << libmath::PrimeFactors<uint_least64_t>::number(factors_max) << std::endl;
  return 0;
}
