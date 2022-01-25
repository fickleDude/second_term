#include <iostream>
#include <fstream>
#include <stdexcept>
#include <memory>
#include <vector>

const size_t BUFFER = 512;

void readFromFile(const char *fileName)
{
  if (fileName == nullptr)
  {
    throw std::ios_base::failure("Wrong file name!");
  }
  std::ifstream inputFile(fileName);
  if (!inputFile)
  {
    throw std::logic_error("Failed to open the file!");
  }
  std::size_t size = BUFFER;
  std::unique_ptr<char[], decltype(&free)> input(static_cast<char *>(malloc(size)), &free);
  if (!input)
  {
    throw std::ios_base::failure("Wrong allocation!");
  }
  std::size_t index = 0;
  while (inputFile)
  {
    inputFile.read(&input[index], BUFFER);
    index += inputFile.gcount();
    if (inputFile.gcount() == BUFFER)
    {
      size += BUFFER;
      std::unique_ptr<char[], decltype(&free)> tmp(static_cast<char *>(realloc(input.get(), size)), &free);
      if (!tmp)
      {
        throw std::ios_base::failure("Failed to reallocate memory!");
      }
      input.release();
      std::swap(input, tmp);
    }
  }
  inputFile.close();
  if (inputFile.is_open())
  {
    throw std::ios_base::failure("Failed to close the file!");
  }
  std::vector<char> output(input.get(), input.get() + index);
  std::cout.write(&output[0], output.size());
}
