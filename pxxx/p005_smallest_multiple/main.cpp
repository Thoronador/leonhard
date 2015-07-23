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
  std::cout << "Hello world!" << std::endl;


  std::vector<libmath::PrimeFactor<uint_least64_t> > factors_current;
  std::vector<libmath::PrimeFactor<uint_least64_t> > factors_max = libmath::PrimeFactors<uint_least64_t>::compute(2);

  uint_least64_t i = 0;
  for (i=1; i<=20; ++i)
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
