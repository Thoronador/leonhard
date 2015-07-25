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

#ifndef DIGITS_HPP_INCLUDED
#define DIGITS_HPP_INCLUDED

#include <algorithm>
#include <stdexcept>
#include <type_traits>

namespace libmath
{
  template<typename intT, typename baseT>
  class Digits
  {
    static_assert(std::is_integral<intT>::value, "Template type intT in Digits must be an integral type!");
    static_assert(std::is_unsigned<intT>::value, "Template type intT in Digits shall be an unsigned type!");
    static_assert(std::is_integral<baseT>::value, "Template type baseT in Digits must be an integral type!");
    static_assert(std::is_unsigned<baseT>::value, "Template type baseT in Digits shall be an unsigned type!");

    public:
      /** \brief splits the parameter into single digits
       *
       * \param n the number that shall be split
       * \param base
       * \return Returns true, if n is a palindrome.
       *         Returns false, if it is not.
       */
      static std::vector<baseT> get(intT n, const baseT base=10);


      /** \brief checks, if the parameter is a palindrome number
       *
       * \param n the number that shall be checked
       * \return Returns true, if n is a palindrome.
       *         Returns false, if it is not.
       */
      static bool palindrome(const intT n, const baseT base=10);
  }; //class


  template<typename intT, typename baseT>
  std::vector<baseT> Digits<intT,baseT>::get(intT n, const baseT base)
  {
    if(base < 2)
      throw std::invalid_argument("Error: base in Digits::get() must be larger than one!");

    if (n<base)
      return std::move(std::vector<baseT>({static_cast<baseT>(n)}));

    std::vector<baseT> digits;

    while (n > 0)
    {
      digits.push_back(n % base);
      n /= base;
    } //while
    //reverse container, because order of digits comes out in reverse from loop above
    std::reverse(digits.begin(), digits.end());

    return std::move(digits);
  }


  template<typename intT, typename baseT>
  bool Digits<intT,baseT>::palindrome(const intT n, const baseT base)
  {
    const std::vector<baseT> dig(get(n, base));

    const typename std::vector<baseT>::size_type len = dig.size();
    const typename std::vector<baseT>::size_type limit = len / 2;
    typename std::vector<baseT>::size_type i = 0;

    for (i=0; i<=limit; ++i)
    {
      if (dig[i] != dig[len-1-i])
        return false;
    } //for
    return true;
  } //function
} //namespace

#endif // DIGITS_HPP_INCLUDED
