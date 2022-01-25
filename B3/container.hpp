#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <cstddef>

const size_t MIN = 0;

class ContainerForFactorial
{
public:
  class IteratorForFactorial;

  using iterator = IteratorForFactorial;
  using const_iterator = const IteratorForFactorial;
  using value_type = size_t;

  ContainerForFactorial();
  ContainerForFactorial(const value_type min, const value_type max);
  iterator begin() const;
  iterator end() const;

private:
  value_type min_;
  value_type max_;
};

#endif
