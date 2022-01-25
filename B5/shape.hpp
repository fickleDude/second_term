#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iosfwd>
#include <vector>

struct Point
{
  int x, y;
};

std::istream &operator>>(std::istream &in, Point &point);
std::ostream &operator<<(std::ostream &out, const Point &point);
int getSquareDistance(const Point &point, const Point &point1);

using Shape = std::vector<Point>;

std::istream &operator>>(std::istream &in, Shape &shape);
std::ostream &operator<<(std::ostream &out, const Shape &shape);
bool isTriangle(const Shape &shape);
bool isSquare(const Shape &shape);
bool isRectangle(const Shape &shape);
bool operator<(const Shape &left, const Shape &right);

#endif
