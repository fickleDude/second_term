#include <iostream>
#include <stdexcept>
#include <vector>
#include "sort_accessory.hpp"

void changeContainer(std::istream &in = std::cin, std::ostream &out = std::cout)
{
  std::vector<int> container;
  int element = 0;
  while ((in >> element) && (element != 0))
  {
    container.push_back(element);
  }
  if ((!in.eof() && in.fail()) || (element != 0))
  {
    throw std::runtime_error("Input failed!");
  }
  if (container.empty())
  {
    return;
  }
  if (container.back() == 1)
  {
    std::vector<int>::iterator it = container.begin();
    while (it != container.end())
    {
      if (*it % 2 == 0)
      {
        it = container.erase(it);
      } else
      {
        ++it;
      }
    }
  }
  if (container.back() == 2)
  {
    std::vector<int>::iterator it = container.begin();
    while (it != container.end())
    {
      if (*it % 3 == 0)
      {
        it = container.insert(it + 1, 3, 1);
        it += 3;
      }
      else
      {
        it++;
      }
    }
  }
  printContainer<std::vector < int>, BracketsAccess<std::vector <int>>>(container, out);
}
