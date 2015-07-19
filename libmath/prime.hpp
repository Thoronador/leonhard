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

#ifndef PRIME_HPP
#define PRIME_HPP

#include <type_traits>
#include <cmath> //for sqrt
#include <map>
#include <vector>

namespace libmath
{

  template<typename intT>
  class Prime
  {
    static_assert(std::is_integral<intT>::value, "Template type intT in Prime must be an integral type!");
    static_assert(std::is_unsigned<intT>::value, "Template type intT in Prime shall be an unsigned type!");
    public:
      /** \brief checks, if the parameter is a prime number
       *
       * \param n the number that shall be checked
       * \return Returns true, if n is a prime number.
       *         Returns false, if it is not.
       */
      static bool is(const intT n);
  }; //struct


  template<typename intT>
  struct PrimeFactor
  {
    static_assert(std::is_integral<intT>::value, "Template type intT in PrimeFactor must be an integral type!");

    intT prime;
    intT exponent;

    //constructor
    PrimeFactor(const intT base, const intT expo)
    : prime(base), exponent(expo)
    { }

    //default constructor
    PrimeFactor()
    : prime(1), exponent(0)
    { }
  }; //struct


  template<typename intT>
  class PrimeFactors
  {
    public:
      static std::vector<PrimeFactor<intT> > compute(const intT n);
  }; //struct


  template<typename intT>
  bool Prime<intT>::is(const intT n)
  {
    if (n<2)
      return false;
    if (n==2)
      return true;
    intT i = 2;
    intT limit = static_cast<intT>(sqrt(n));
    for (i=2; i<=limit; ++i)
    {
      if (n%i == 0)
        return false;
    } // for i
    return true;
  }

  template<typename intT>
  std::vector<PrimeFactor<intT> > PrimeFactors<intT>::compute(const intT n)
  {
    std::vector<PrimeFactor<intT> > result;
    if (n<=3)
    {
      result.push_back(PrimeFactor<intT>(n, 1));
      return std::move(result);
    } //if

    std::map<intT, intT> data;

    intT i = 2;
    intT number = n;
    for (i=2; i<=number; ++i)
    {
      if (Prime<intT>::is(i))
      {
        while (number % i == 0)
        {
          ++data[i];
          number /= i;
        }
      } //if i is prime
    } //for

    auto iter = data.begin();
    for (; iter!= data.end(); ++iter)
    {
      result.push_back(PrimeFactor<intT>(iter->first, iter->second));
    } //for
    return std::move(result);
  } //function

} //namespace

#endif // PRIME_HPP
