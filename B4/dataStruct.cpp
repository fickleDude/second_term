#include "dataStruct.hpp"
#include <iostream>
#include "skipWhiteSpace.hpp"
#include <boost/io/ios_state.hpp>

int MAX = 5;
int MIN = -5;

bool operator<(const DataStruct &left, const DataStruct &right)
{
  if (left.key1 != right.key1)
  {
    return left.key1 < right.key1;
  } else if (left.key2 != right.key2)
  {
    return left.key2 < right.key2;
  }
  return left.str.length() < right.str.length();
}

std::istream &operator>>(std::istream &in, DataStruct &data)
{
  std::istream::sentry sentry(in);
  if (!sentry)
  {
    return in;
  }
  boost::io::ios_flags_saver guard(in);
  int key1 = 0;
  int key2 = 0;
  char ch = ' ';
  char ch1 = ' ';
  std::noskipws(in);
  in >> skipWhiteSpace >> key1 >> skipWhiteSpace >> ch >> skipWhiteSpace >> key2
  >> skipWhiteSpace >> ch1;
  if ((ch != ',') || (key1 > MAX) || (key1 < MIN) ||
    (ch1 != ',') || (key2 > MAX) || (key2 < MIN))
  {
    in.setstate(std::ios_base::failbit);
  }
  std::string str;
  std::getline(in >> skipWhiteSpace, str);
  if (str.empty())
  {
    in.setstate(std::ios_base::failbit);
    return in;
  }
  data = {key1, key2, str};
  return in;
}

std::ostream &operator<<(std::ostream &out, const DataStruct &data)
{
  std::ostream::sentry sentry(out);
  if (sentry)
  {
    boost::io::ios_flags_saver guard(out);
    out << data.key1 << ',' << data.key2 << ',' << data.str;
  }
  return out;
}
