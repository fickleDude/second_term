#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iterator>
#include "container.hpp"

class ContainerForFactorial::IteratorForFactorial :
    public std::iterator<std::bidirectional_iterator_tag, size_t, ptrdiff_t, const size_t*, size_t>
{
public:
  friend class ContainerForFactorial;
  bool operator==(const IteratorForFactorial&it) const;
  bool operator!=(const IteratorForFactorial&it) const;
  size_t operator*() const;
  IteratorForFactorial& operator++();
  IteratorForFactorial operator++(int);
  IteratorForFactorial& operator--();
  IteratorForFactorial operator--(int);

private:
  size_t index_;
  size_t value_;

  IteratorForFactorial(const size_t index);
  size_t countValue(const size_t index);
};

#endif
