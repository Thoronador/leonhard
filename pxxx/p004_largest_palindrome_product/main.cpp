#include <cstdint>
#include <iostream>
#include <map>
#include <utility> //std::pair
#include "../../libmath/digits.hpp"

int main()
{
  std::map<uint_fast32_t, std::pair<uint_fast32_t,uint_fast32_t> > palindromes;

  uint_fast32_t i, j;
  for (i=999; i>=100; --i)
    for (j=i; j>=100; --j)
    {
      if (libmath::Digits<uint_fast32_t, uint_fast8_t>::palindrome(j*i, 10))
      {
        palindromes[j*i] = std::pair<uint_fast32_t,uint_fast32_t>(i, j);
        break; //We can get out of loop, because no product in this loop will be larger.
      }
    } //for j

  const auto largest = palindromes.rbegin();
  if (largest == palindromes.rend())
  {
    std::cout << "Could not find any palindromes!" << std::endl;
    return 1;
  }
  std::cout << "Maximum palindrome that is product of two two-digit numbers is "
            <<  largest->first << " as product of " << largest->second.first
            << " and " << largest->second.second << "." << std::endl;
  return 0;
}
