#include <random>
#include <vector>
#include <stdexcept>
#include <iostream>
#include "sort_accessory.hpp"

void fillRandom(double *array, int size)
{
  if (array == nullptr)
  {
    throw std::invalid_argument("Invalid array!");
  }
  if (size < 0)
  {
    throw std::invalid_argument("Invalid size of array!");
  }
  static std::random_device rd;
  for (int i = 0; i < size; i++)
  {
    array[i] = (std::generate_canonical<double, std::numeric_limits<double>::digits>(rd) - 0.5) * 2.0;
  }
}

void vectorSort(const char *comparator, int size, std::ostream &out = std::cout)
{
  if (size < 0)
  {
    throw std::invalid_argument("Invalid size of array!");
  }
  std::vector<double> vector(size);
  fillRandom(&vector[0], vector.size());
  printContainer<std::vector <double>, BracketsAccess<std::vector <double>>>(vector, out);
  selectionSort<std::vector <double>, BracketsAccess<std::vector <double>>>(vector, convertSortOption(comparator));
  printContainer<std::vector <double>, BracketsAccess<std::vector <double>>>(vector, out);
}
