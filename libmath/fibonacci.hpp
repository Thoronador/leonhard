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

#include <cstdint>
#include <cmath> //for sqrt()

namespace libmath
{
  /** \brief struct to provide functions to calculate Fibonacci numbers
   *
   * \remarks The type intT should an unsigned integer type (e.g. uint32_t oder uint64_t).
   *          The values f0 and f1 are the values of the first two Fibinacci numbers.
   *          E.g., if your sequence shall be 1, 2, 3, 5, 8, 13, 21, ...,
   *          then set f0 to 1 and f2 to 2.
   *          If your sequence shall be 0, 1, 1, 2, 3, 5, 8, ...,
   *          then set f0 to 0 and f2 to 1.
   */
  template<typename intT, intT f0, intT f1> struct Fibonacci
  {
    /** \brief calculates the n-th Fibonacci number by using naive recursion
     *
     * \param n the zero-based index of the desired Fibonacci number
     * \return Returns the n-th Fibonacci number.
     */
    static intT recursive(unsigned int n)
    {
      if (n == 0)
        return f0;
      if (n == 1)
        return f1;
      return recursive(n-1)+recursive(n-2);
    }


    /** \brief calculates the n-th Fibonacci number by using fast recursion
     *
     * \param n the zero-based index of the desired Fibonacci number
     * \return Returns the n-th Fibonacci number.
     */
    static intT recursive_fast(unsigned int n)
    {
      //for larger values of n, use alternative formula
      if (n>6)
        return 4*recursive_fast(n-3)+recursive_fast(n-6);
      //For n in [0;6] fall back to normal recursive function.
      return recursive(n);
    }


    /** \brief calculates the n-th Fibonacci number by using iteration
     *
     * \param n the zero-based index of the desired Fibonacci number
     * \return Returns the n-th Fibonacci number.
     */
    static intT iterative(unsigned int n)
    {
      unsigned int i;
      intT last;
      intT last_but_one;
      intT fibo;

      if (n == 0)
        return f0;
      if (n == 1)
        return f1;

      last = f1;
      last_but_one = f0;

      for (i=2; i <= n; ++i)
      {
        // add the both most recent numbers
        fibo = last + last_but_one;
        // shift older numbers
        last_but_one = last;
        last = fibo;
      } //for
      return fibo;
    }

    /** \brief calculates the n-th Fibonacci number by using the formula of Moivre and Binet
     *
     * \param n the zero-based index of the desired Fibonacci number
     * \return Returns the n-th Fibonacci number.
     * \remarks Since this method uses floating point calculations internally,
     *          it can (and will) result in decreased precision for large values
     *          of n.
     */
    static intT direct(unsigned int n)
    {
      static const long double phi = (1.0L + sqrt(5.0L)) / 2.0L;
      static const long double psi = (1.0L - sqrt(5.0L)) / 2.0L;

      return static_cast<intT>((pow(phi, n) - pow(psi, n)) / (phi - psi));
    }
  }; //struct

  //define shorthands for some common Fibonacci sequences
  typedef Fibonacci<uint64_t, 0, 1> DefaultFibonacci;
  typedef Fibonacci<uint64_t, 1, 2> DistinctFibonacci;
} //namespace
