#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include "dataStruct.hpp"

int main()
{
  std::vector <DataStruct> vector((std::istream_iterator<DataStruct>(std::cin)), std::istream_iterator<DataStruct>());
  if (std::cin.bad())
  {
    std::cerr << "Wrong input!\n";
    return 1;
  }
  if (!std::cin.eof())
  {
    std::cerr << "Wrong parameters input!\n";
    return 1;
  }
  std::sort(vector.begin(), vector.end());
  std::copy(vector.begin(), vector.end(), std::ostream_iterator<DataStruct>(std::cout, "\n"));
  return 0;
}
