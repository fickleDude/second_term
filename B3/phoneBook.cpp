#include "interface.hpp"
#include <istream>

void phoneBook(std::istream &in, std::ostream &out)
{
  Bookmark bookmark;
  while (in >> std::ws, !in.eof())
  {
    convertCommand(in)(bookmark, out);
  }
  if (!in.eof())
  {
    throw std::invalid_argument("Failed to read!");
  }
}
