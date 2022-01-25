#include <iostream>
#include <string>
#include <set>
#include <iterator>

void firstTask(std::istream &in, std::ostream &out)
{
  std::set <std::string> words((std::istream_iterator<std::string>(in)), std::istream_iterator<std::string>());
  if (!in.eof())
  {
    throw std::ios_base::failure("Error occurred while reading data!\n");
  }
  std::copy(words.begin(), words.end(), std::ostream_iterator<std::string>(out, "\n"));
}
