#include <iostream>
#include <vector>
#include <forward_list>
#include <cstring>
#include "sort_accessory.hpp"

void sort(const char *comparator, std::istream &in = std::cin, std::ostream &out = std::cout)
{
  SortOption direction(convertSortOption(comparator));
  if ((direction != ASCENDING) && (direction != DESCENDING))
  {
    throw std::invalid_argument("Wrong compare parameter!");
  }
  std::vector<int> vector;
  int element = 0;
  while (!in.eof() && (in >> element))
  {
    vector.push_back(element);
  }
  if (!in.eof())
  {
    throw std::invalid_argument("Invalid character!");
  }
  if (vector.size() == 0)
  {
    return;
  }
  std::vector<int> vectorAt = vector;
  selectionSort<std::vector <int>, AtAccess<std::vector <int>>>(vectorAt, direction);
  printContainer<std::vector <int>, AtAccess<std::vector <int>>>(vectorAt, out);
  std::forward_list<int> list(vector.begin(), vector.end());
  selectionSort<std::forward_list <int>, IteratorAccess<std::forward_list <int>>>(list, direction);
  printContainer<std::forward_list <int>, IteratorAccess<std::forward_list <int>>>(list, out);
  selectionSort<std::vector <int>, BracketsAccess<std::vector <int>>>(vector, direction);
  printContainer<std::vector <int>, BracketsAccess<std::vector <int>>>(vector, out);
}
