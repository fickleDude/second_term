#ifndef ACCESSORY_HPP
#define ACCESSORY_HPP
#include <cstddef>

template<typename Container>
struct BracketsAccess
{
  using index = size_t;
  using value = typename Container::value_type;

  static index begin(const Container &)
  {
    return 0;
  }

  static index end(const Container &obj)
  {
    return obj.size();
  }

  static value &getElement(Container &obj, size_t index)
  {
    return obj[index];
  }
};

template<typename Container>
struct AtAccess
{
  using index = size_t;
  using value = typename Container::value_type;

  static index begin(const Container &)
  {
    return 0;
  }

  static index end(const Container &obj)
  {
    return obj.size();
  }

  static value &getElement(Container &obj, size_t index)
  {
    return obj.at(index);
  }
};

template<typename Container>
struct IteratorAccess
{
  using index = typename Container::iterator;
  using value = typename Container::value_type;

  static index begin(Container &obj)
  {
    return obj.begin();
  }

  static index end(Container &obj)
  {
    return obj.end();
  }

  static value &getElement(Container &, index index)
  {
    return *index;
  }
};

#endif
