#include <iostream>
#include <stdexcept>
#include <string>
#include <cstdlib>

void sort(const char *comparator, std::istream &in = std::cin, std::ostream &out = std::cout);

void readFromFile(const char *fileName);

void vectorSort(const char *comparator, int size, std::ostream &out = std::cout);

void changeContainer(std::istream &in = std::cin, std::ostream &out = std::cout);

int main(int argc, char *argv[])
{
  if (argc > 1 && argc < 5)
  {
    if (argv[1][1] != '\0')
    {
      std::cerr << "Invalid task number!";
      return 1;
    }
    int task = std::atoi(argv[1]);
    switch (task)
    {
      case 1:
        if (argc != 3)
        {
          std::cerr << "Amount of parameters must be 3!";
          return 1;
        }
        try
        {
          sort(argv[2]);
        }
        catch (const std::exception &e)
        {
          std::cerr << "\n" << e.what() << "\n";
          return 2;
        }
        break;
      case 2:
        if (argc != 3)
        {
          std::cerr << "Amount of parameters must be 3!";
          return 1;
        }
        try
        {
          readFromFile(argv[2]);
        }
        catch (const std::exception &e)
        {
          std::cerr << "\n" << e.what() << "\n";
          return 2;
        }
        break;
      case 3:
        if (argc != 2)
        {
          std::cerr << "Amount of parameters must be 2!";
          return 1;
        }
        try
        {
          changeContainer();
        }
        catch (const std::exception &e)
        {
          std::cerr << "\n" << e.what() << "\n";
          return 2;
        }
        break;
      case 4:
        if (argc != 4)
        {
          std::cerr << "Amount of parameters must be 4!";
          return 1;
        }
        try
        {
          char *simbol = nullptr;
          size_t size = static_cast<size_t>(strtol(argv[3], &simbol, 0));
          if (*simbol != '\0')
          {
            std::cerr << "Invalid array size!";
            return 2;
          }
          vectorSort(argv[2], size);
        }
        catch (const std::exception &e)
        {
          std::cerr << "\n" << e.what() << "\n";
          return 2;
        }
        break;
      default:
        std::cerr << "Wrong number of task!";
        return 1;
    }
  } else if (argc < 2 || argc > 4)
  {
    std::cerr << "Wrong amount of parameters!";
    return 1;
  }
  return 0;
}
