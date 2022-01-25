#include "container.hpp"
#include "iterator.hpp"

ContainerForFactorial::ContainerForFactorial():
  min_(MIN),
  max_(MIN)
{}


ContainerForFactorial::ContainerForFactorial(const value_type min, const value_type max) :
  min_(min),
  max_(max)
{}

ContainerForFactorial::iterator ContainerForFactorial::begin() const
{
  return ContainerForFactorial::IteratorForFactorial(min_);
}

ContainerForFactorial::iterator ContainerForFactorial::end() const
{
  return ContainerForFactorial::IteratorForFactorial(max_);
}
