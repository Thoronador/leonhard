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
  int_fast32_t a, b, c;

  for (a = 3; a <= 1000 - 2; ++a)
  {
    for (b = a + 1; b <= 1000 - 1; ++b)
    {
      c = 1000 - a - b;
      if (a*a + b*b == c*c)
      {
        std::cout << "a: " << a << std::endl
                  << "b: " << b << std::endl
                  << "c: " << c << std::endl
                  << "Product a*b*c: " << a * b * c << std::endl;
      } //if
    } //for b
  } //for a
  return 0;
}
