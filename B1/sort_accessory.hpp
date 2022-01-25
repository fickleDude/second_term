#ifndef SORT_ACCESSORY_HPP
#define SORT_ACCESSORY_HPP

#include <cstring>
#include <stdexcept>
#include <iostream>
#include "accessory.hpp"

enum SortOption
{
  ASCENDING,
  DESCENDING
};

inline SortOption convertSortOption(const char *line)
{
  if (strcmp(line, "ascending") == 0)
  {
    return ASCENDING;
  }
  if (strcmp(line, "descending") == 0)
  {
    return DESCENDING;
  }
  throw std::invalid_argument("Wrong compare parameter!");
}

template<typename T>
bool comparator(const T &first, const T &second, SortOption option)
{
  switch (option)
  {
    case ASCENDING:
      return (first > second);
    case DESCENDING:
      return (first < second);
    default:
      throw std::invalid_argument("Wrong compare parameter!");
  }
}

template<typename Container, typename Access>
void selectionSort(Container &container, SortOption direction)
{
  using indexType = typename Access::index;
  indexType left = Access::begin(container);
  indexType right = Access::end(container);
  for (indexType i = left; i != right; i++)
  {
    typename Access::value swapEl = Access::getElement(container, i);
    indexType index = i;
    for (indexType j = i; j != right; j++)
    {
      typename Access::value current = Access::getElement(container, j);
      if (comparator(swapEl, current, direction))
      {
        swapEl = current;
        index = j;
      }
    }
    std::swap(Access::getElement(container, i), Access::getElement(container, index));
  }
}

template<typename Container, typename Access>
void printContainer(Container &container, std::ostream &out)
{
  using indexType = typename Access::index;
  indexType begin = Access::begin(container);
  indexType end = Access::end(container);
  for (indexType i = begin; i != end; i++)
  {
    out << Access::getElement(container, i) << " ";
  }
  out << "\n";
}

#endif
