#include <ostream>
#include <algorithm>

#include "container.hpp"
#include "iterator.hpp"

void containerOfFactorials(std::ostream &out)
{
  ContainerForFactorial factorial(1, 10);
  std::copy(factorial.begin(), std::next(factorial.end()), std::ostream_iterator<size_t>(out, " "));
  out << '\n';
  std::reverse_copy(factorial.begin(), std::next(factorial.end()), std::ostream_iterator<size_t>(out, " "));
  out << '\n';
}
