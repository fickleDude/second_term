#include "interface.hpp"
#include "container.hpp"
#include <iostream>
#include <stdexcept>

void phoneBook(std::istream &in, std::ostream &out);

void containerOfFactorials(std::ostream &out);

int main(int argc, char *argv[])
{
  try
  {
    if (argc != 2)
    {
      std::cerr << "Wrong amount of parameters must be 2!";
      return 1;
    }
    char *symbol = nullptr;
    const int task = std::strtol(argv[1], &symbol, 0);
    if (*symbol != '\0')
    {
      std::cerr << "Invalid task number!";
      return 1;
    }
    switch (task)
    {
      case 1:
        phoneBook(std::cin, std::cout);
        break;
      case 2:
        containerOfFactorials(std::cout);
        break;
      default:
        std::cerr << "Unknown task!";
        return 1;
    }
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what();
    return 2;
  }
  return 0;
}
