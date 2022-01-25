#include "circle.hpp"

#define _USE_MATH_DEFINES

#include <cmath>
#include <stdexcept>
#include <ostream>

baeva::Circle::Circle(double r, const point_t &center) :
  r_(r),
  center_(center)
{
  if (r <= 0)
  {
    throw std::invalid_argument("Wrong radius");
  }
};

double baeva::Circle::getArea() const noexcept
{
  return M_PI * std::pow(r_, 2);
}

baeva::rectangle_t baeva::Circle::getFrameRect() const noexcept
{
  return rectangle_t{2.0 * r_, 2.0 * r_, center_};
}

void baeva::Circle::move(const point_t &newCenter) noexcept
{
  center_ = newCenter;
}

void baeva::Circle::move(double shiftX, double shiftY) noexcept
{
  center_.x += shiftX;
  center_.y += shiftY;
}

baeva::point_t baeva::Circle::getCenter() const noexcept
{
  return center_;
}

double baeva::Circle::getRadius() const noexcept
{
  return r_;
}

void baeva::Circle::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Wrong coefficient");
  }
  r_ *= coefficient;
}

std::ostream &baeva::Circle::printInfo(std::ostream &out) const
{
  out << "radius: " << r_ << " position: (" << center_.x << ", " << center_.y << ")\n";
  return out;
}
