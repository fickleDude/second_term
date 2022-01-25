#ifndef DATA_STRUCT_HPP
#define DATA_STRUCT_HPP

#include <string>
#include <iosfwd>

struct DataStruct
{
  int key1;
  int key2;
  std::string str;
};

bool operator<(const DataStruct &left, const DataStruct &right);
std::istream &operator>>(std::istream &in, DataStruct &data);
std::ostream &operator<<(std::ostream &out, const DataStruct &data);

#endif
