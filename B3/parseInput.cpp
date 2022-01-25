#include <string>
#include <istream>
#include "skipWhiteSpace.hpp"

std::string parseName(std::istream &in)
{
  std::string name;
  in >> skipWhiteSpace;
  std::string temp;
  char ch = in.get();
  if (ch == '\"')
  {
    ch = in.get();
    while ((ch != '\"') && !in.eof() && (ch != '\n'))
    {
      if (ch == '\\')
      {
        ch = in.get();
        if (!((ch == '\\') || (ch == '\"')))
        {
          getline(in, temp);
          return "";
        }
      }
      name += ch;
      ch = in.get();
    }
  }
  else if (ch != '\n')
  {
    getline(in, temp);
    return "";
  }
  else
  {
    return "";
  }
  return name;
}

std::string parseNumber(std::istream &in)
{
  std::string number;
  in >> skipWhiteSpace >> number;
  if (!number.empty())
  {
    auto it = number.begin();
    while (it != number.end())
    {
      if (!isdigit(*it))
      {
        return "";
      }
      it++;
    }
  }
  return number;
}

std::string parseMarkName(std::istream &in)
{
  std::string markName;
  in >> skipWhiteSpace >> markName;
  if (!markName.empty())
  {
    auto it = markName.begin();
    while (it != markName.end())
    {
      if (!std::isalnum(*it) && *it != '-')
      {
        return "";
      }
      it++;
    }
  }
  return markName;
}
