/*
 -------------------------------------------------------------------------------
    This file is part of libmath.
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

#ifndef COLLATZ_HPP
#define COLLATZ_HPP

#include <limits>
#include <stdexcept>
#include <type_traits>
#include <vector>

namespace libmath
{
  template<typename intT>
  struct Collatz
  {
    static_assert(std::is_integral<intT>::value, "Template type intT in struct Collatz must be an integral type!");
    static_assert(std::is_unsigned<intT>::value, "Template type intT in struct Collatz must be an unsigned type!");


    /** \brief calculates the Collatz sequence for a given starting number
     *
     * \param n the starting number of the Collatz sequence; must not be zero
     * \return Returns a vector that contains all elements of the Collatz
     *         sequence starting with n.
     */
    static std::vector<intT> getSequenceFor(intT n);
  }; //class


  template<typename intT>
  std::vector<intT> Collatz<intT>::getSequenceFor(intT n)
  {
    if (n==0)
      throw std::invalid_argument("Starting value n of Collatz sequence must not be zero!");
    const intT limitForStuff = (std::numeric_limits<intT>::max() -1) / 3;
    std::vector<intT> result;
    result.push_back(n);
    while (n != 1)
    {
      if (n % 2 == 0)
      {
        n /= 2;
      }
      else
      {
        if (n > limitForStuff)
        {
          std::cout << "Info: n is " << n << std::endl;
          throw std::range_error("Cannot compute 3*n+1 without range overflow!");
        }

        n = 3*n+1;
      }
      result.push_back(n);
    } //while
    return std::move(result);
  }
} //namespace

#endif // COLLATZ_HPP
