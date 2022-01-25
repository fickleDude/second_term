#include "circle.hpp"

#define _USE_MATH_DEFINES

#include <cmath>
#include <stdexcept>

Circle::Circle(double r, const point_t &center) :
  r_(r),
  center_(center)
{
  if (r <= 0)
  {
    throw std::invalid_argument("Wrong radius");
  }
};

double Circle::getArea() const
{
  return M_PI * pow(r_, 2);
}

rectangle_t Circle::getFrameRect() const
{
  return rectangle_t{2.0 * r_, 2.0 * r_, center_};
}

void Circle::move(const point_t &newCenter)
{
  center_ = newCenter;
}

void Circle::move(double shiftX, double shiftY)
{
  center_.x += shiftX;
  center_.y += shiftY;
}

std::ostream &Circle::printInfo(std::ostream &out) const
{
  out << "radius: " << r_ << " position: (" << center_.x << ", " << center_.y << ")\n";
  return out;
}
