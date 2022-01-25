#include "triangle.hpp"
#include <stdexcept>
#include <cmath>
#include <cstdlib>

Triangle::Triangle(const point_t &a, const point_t &b, const point_t &c) :
  a_(a),
  b_(b),
  c_(c)
{
  if (getArea() == 0)
  {
    throw std::invalid_argument("Wrong coordinates");
  }
};

double Triangle::getArea() const
{
  return (std::abs((a_.x - c_.x) * (b_.y - c_.y) - (b_.x - c_.x) * (a_.y - c_.y))) / 2.0;
}

rectangle_t Triangle::getFrameRect() const
{
  double xMin = std::fmin(a_.x, std::fmin(b_.x, c_.x));
  double yMin = std::fmin(a_.y, std::fmin(b_.y, c_.y));
  double xMax = std::fmax(a_.x, std::fmax(b_.x, c_.x));
  double yMax = std::fmax(a_.y, std::fmax(b_.y, c_.y));
  return rectangle_t{xMax - xMin, yMax - yMin, { xMin + (xMax - xMin) / 2.0, yMin + (yMax - yMin) / 2.0}};
}

void Triangle::move(const point_t &newCenter)
{
  double dx = newCenter.x - (a_.x + b_.x + c_.x) / 3.0;
  double dy = newCenter.y - (a_.y + b_.y + c_.y) / 3.0;
  move(dx, dy);
}

void Triangle::move(double shiftX, double shiftY)
{
  a_.x += shiftX;
  a_.y += shiftY;
  b_.x += shiftX;
  b_.y += shiftY;
  c_.x += shiftX;
  c_.y += shiftY;
}

std::ostream &Triangle::printInfo(std::ostream &out) const
{
  out << "A: (" << a_.x << ", " << a_.y << ")\n" << "B: (" << b_.x << ", " << b_.y << ")\n"
      << "C: (" << c_.x << ", " << c_.y << ")\n" << "center_: (" << (a_.x + b_.x + c_.x) / 3.0 << ", "
      << (a_.y + b_.y + c_.y) / 3.0 << ")\n";
  return out;
}
