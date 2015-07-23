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
#include "../../libmath/collatz.hpp"

int main()
{
  uint32_t i;
  uint64_t max_len = 0;
  uint32_t max_i = 0;

  for (i=1; i < 1000000; ++i)
  {
    const auto collatzSequence = libmath::Collatz<uint64_t>::getSequenceFor(i);
    if (collatzSequence.size() > max_len)
    {
      max_len = collatzSequence.size();
      max_i = i;
    }
  } //for
  std::cout << "The starting number in [1;1000000) that produces the longest Collatz sequence is "
            << max_i << " with " << max_len << " elements in the sequence."
            << std::endl;
  return 0;
}
