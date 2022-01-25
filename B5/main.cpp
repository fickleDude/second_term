#include <iostream>
#include <stdexcept>
#include <cstdlib>

void firstTask(std::istream &in, std::ostream &out);

void secondTask(std::istream &in, std::ostream &out);

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cerr << "Wrong amount of parameters!\n";
    return 1;
  }
  if (argv[1][1] != '\0')
  {
    std::cerr << "Wrong number of task!\n";
    return 1;
  }
  try
  {
    switch (std::atoi(argv[1]))
    {
      case 1:
        firstTask(std::cin, std::cout);
        break;
      case 2:
        secondTask(std::cin, std::cout);
        break;
      default:
        std::cerr << "Wrong number of task!\n";
        return 1;
    }
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  return 0;
}
