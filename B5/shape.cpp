#include "shape.hpp"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iterator>
#include <boost/io/ios_state.hpp>
#include "skipWhiteSpace.hpp"

const unsigned AMOUNT_OF_TRIANGLE_VERTICES = 3;
const unsigned AMOUNT_OF_RECTANGLE_VERTICES = 4;

std::istream &operator>>(std::istream &in, Point &point)
{
  std::istream::sentry sentry(in);
  if (!sentry)
  {
    return in;
  }
  boost::io::ios_flags_saver guard(in);
  int x = 0;
  int y = 0;
  char openBracket = ' ';
  char closeBracket = ' ';
  char semicolon = ' ';
  in >> skipWhiteSpace >> std::noskipws >> openBracket >> skipWhiteSpace >> std::noskipws >> x
     >> skipWhiteSpace >> std::noskipws >> semicolon >> skipWhiteSpace >> std::noskipws >> y
     >> skipWhiteSpace >> std::noskipws >> closeBracket;
  if ((in.fail()) || (openBracket != '(') || (semicolon != ';') || (closeBracket != ')'))
  {
    in.clear(in.rdstate() & ~std::ios_base::eofbit);
    for (int i = 0; i < 5; i++)
    {
      in.unget();
    }
    in.setstate(std::ios_base::failbit);
    return in;
  }
  point = {x, y};
  return in;
}

std::ostream &operator<<(std::ostream &out, const Point &p)
{
  std::ostream::sentry sentry(out);
  if (sentry)
  {
    boost::io::ios_flags_saver guard(out);
    out << "(" << p.x << ";" << p.y << ")";
  }
  return out;
}

int getSquareDistance(const Point &p, const Point &p1)
{
  return std::pow(std::abs(p.x - p1.x), 2) + std::pow(std::abs(p.y - p1.y), 2);
}

bool isTriangle(const Shape &shape)
{
  return shape.size() == AMOUNT_OF_TRIANGLE_VERTICES;
}

bool isRectangle(const Shape &shape)
{
  return (shape.size() == AMOUNT_OF_RECTANGLE_VERTICES) &&
         (getSquareDistance(shape[0], shape[1]) == getSquareDistance(shape[2], shape[3]))
         && (getSquareDistance(shape[0], shape[3]) == getSquareDistance(shape[2], shape[1])) &&
         (getSquareDistance(shape[1], shape[3]) == getSquareDistance(shape[0], shape[2]));
}

bool isSquare(const Shape &shape)
{
  return (isRectangle(shape)) && (getSquareDistance(shape[0], shape[1]) == getSquareDistance(shape[1], shape[2]));
}

std::istream &operator>>(std::istream &in, Shape &shape)
{
  std::istream::sentry sentry(in);
  if (!sentry)
  {
    return in;
  }
  boost::io::ios_flags_saver guard(in);
  int vertices = 0;
  in >> skipWhiteSpace >> vertices;
  if ((in.fail()) || (in.eof()))
  {
    in.clear(in.rdstate() & ~std::ios_base::eofbit);
    in.unget();
    in.setstate(std::ios_base::failbit);
    return in;
  }
  if (vertices < 3)
  {
    in.unget();
    in.setstate(std::ios_base::failbit);
    return in;
  }
  shape.clear();
  for (int i = 0; i < vertices; i++)
  {
    Point point = {0, 0};
    in >> skipWhiteSpace >> point;
    if (in.fail())
    {
      if (shape.size() != 0)
      {
        shape.clear();
      }
      in.clear(in.rdstate() & std::ios_base::failbit);
      return in;
    }
    shape.push_back(point);
  }
  in.clear();
  return in;
}

std::ostream &operator<<(std::ostream &out, const Shape &shape)
{
  std::ostream::sentry sentry(out);
  if (sentry)
  {
    boost::io::ios_flags_saver guard(out);
    out << shape.size() << " ";
    std::copy(shape.begin(), shape.end(), std::ostream_iterator<Point>(out, " "));
  }
  return out;
}

bool operator<(const Shape &left, const Shape &right)
{
  if (left.size() != right.size())
  {
    return left.size() < right.size();
  }
  return ((isSquare(left) && !isSquare((right))) || (isRectangle(left) && !isRectangle(right)));
}
