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

#include <array>
#include <cstdint>
#include <fstream>
#include <string>
#include <iostream>

int main(int argc, char** argv)
{
  std::string fileName = "digits.txt";

  if (argc > 1)
  {
    if (argv != nullptr)
    {
      if (argv[1] != nullptr)
      {
        fileName = std::string(argv[1]);
      }
    } //if argv not null
  } //if argument is given


  std::ifstream inputStream;
  inputStream.open(fileName, std::ios_base::in | std::ios_base::binary);
  if (!inputStream.good() || !inputStream.is_open())
  {
    std::cout << "Error: Could not open file " << fileName << "for reading!"
              << std::endl;
    return 1;
  }

  const uint64_t cDigitCount = 1000;
  const uint64_t cSeriesLength = 13;

  std::array<uint_fast8_t, cDigitCount> digits;
  uint_fast64_t i = 0;
  while (i < cDigitCount - 1)
  {
    std::string line;
    std::getline(inputStream, line, '\n');
    if (!inputStream.good() || inputStream.eof())
    {
      std::cout << "Error: Could not read " << cDigitCount << " digits from file "
                 << fileName << "!" << std::endl;
      return 1;
    }
    for (auto iter = line.begin(); iter != line.end(); ++iter)
    {
      switch (*iter)
      {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
             digits[i] = static_cast<uint_fast8_t>(*iter) - static_cast<uint_fast8_t>('0');
             break;
        default:
             std::cout << "Error: Invalid digit!" << std::endl;
             return 1;
      } //swi
      ++i;
    } //for
  } //while


  uint_fast64_t max_prod = 0;
  uint_fast64_t max_start_idx = 0;

  for (i = 0; i <= cDigitCount - cSeriesLength; ++i)
  {
    uint_fast32_t j = 0;
    uint_fast64_t product = 1;
    for(j = 0; j < cSeriesLength; ++j)
    {
      product *= digits[i+j];
    }
    if (product > max_prod)
    {
      max_prod = product;
      max_start_idx = i;
    }
  } //for i

  std::cout << "The largest product is " << max_prod << " and starts at digit "
            << max_start_idx + 1 << "." << std::endl << "Digits in sequence:";
  for(i = max_start_idx; i < max_start_idx + cSeriesLength; ++i)
    std::cout << " " << static_cast<unsigned int>(digits[i]);
  std::cout << std::endl;
  return 0;
}
