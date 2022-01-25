#include "iterator.hpp"
#include <stdexcept>

size_t ContainerForFactorial::IteratorForFactorial::countValue(const size_t index)
{
  if (index <= 1)
  {
    return 1;
  }
  return index * countValue(index - 1);
}

ContainerForFactorial::IteratorForFactorial::IteratorForFactorial(const size_t index) :
  index_(index),
  value_(countValue(index))
{}

bool ContainerForFactorial::IteratorForFactorial::operator==(const IteratorForFactorial& it) const
{
  return index_ == it.index_;
}

bool ContainerForFactorial::IteratorForFactorial::operator!=(const IteratorForFactorial& it) const
{
  return !(*this == it.index_);
}

size_t ContainerForFactorial::IteratorForFactorial::operator*() const
{
  return value_;
}

ContainerForFactorial::IteratorForFactorial& ContainerForFactorial::IteratorForFactorial::operator++()
{
  index_++;
  value_ = value_ * index_;
  return *this;
}

ContainerForFactorial::IteratorForFactorial ContainerForFactorial::IteratorForFactorial::operator++(int)
{
  IteratorForFactorial tmp(*this);
  this->operator++();
  return tmp;
}

ContainerForFactorial::IteratorForFactorial& ContainerForFactorial::IteratorForFactorial::operator--()
{
  if (index_ == 0)
  {
    throw std::runtime_error("Index out of range!");
  }
  value_ = value_ / index_;
  index_--;
  return *this;
}

ContainerForFactorial::IteratorForFactorial ContainerForFactorial::IteratorForFactorial::operator--(int)
{
  IteratorForFactorial tmp(*this);
  this->operator--();
  return tmp;
}
