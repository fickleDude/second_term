#include "skipWhiteSpace.hpp"

std::istream& skipWhiteSpace(std::istream& in)
{
  char ch = in.get();
  while ((iswspace(ch)) && (ch != '\n'))
  {
    in.get(ch);
  }
  in.unget();
  return in;
}
