#include "triangle.hpp"
#include <stdexcept>
#include <cmath>
#include <cstdlib>
#include <ostream>

baeva::Triangle::Triangle(const point_t &a, const point_t &b, const point_t &c) :
  a_(a),
  b_(b),
  c_(c)
{
  if (getArea() == 0)
  {
    throw std::invalid_argument("Wrong coordinates");
  }
};

double baeva::Triangle::getArea() const noexcept
{
  return (std::abs((a_.x - c_.x) * (b_.y - c_.y) - (b_.x - c_.x) * (a_.y - c_.y))) / 2.0;
}

baeva::rectangle_t baeva::Triangle::getFrameRect() const noexcept
{
  double xMin = std::fmin(a_.x, std::fmin(b_.x, c_.x));
  double yMin = std::fmin(a_.y, std::fmin(b_.y, c_.y));
  double xMax = std::fmax(a_.x, std::fmax(b_.x, c_.x));
  double yMax = std::fmax(a_.y, std::fmax(b_.y, c_.y));
  return rectangle_t{xMax - xMin, yMax - yMin, {xMin + (xMax - xMin) / 2.0, yMin + (yMax - yMin) / 2.0}};
}

void baeva::Triangle::move(const point_t &newCenter) noexcept
{
  double dx = newCenter.x - (a_.x + b_.x + c_.x) / 3.0;
  double dy = newCenter.y - (a_.y + b_.y + c_.y) / 3.0;
  move(dx, dy);
}

void baeva::Triangle::move(double shiftX, double shiftY) noexcept
{
  a_.x += shiftX;
  a_.y += shiftY;
  b_.x += shiftX;
  b_.y += shiftY;
  c_.x += shiftX;
  c_.y += shiftY;
}

void baeva::Triangle::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Wrong coefficient");
  }
  point_t center{(a_.x + b_.x + c_.x) / 3, (a_.y + b_.y + c_.y) / 3};
  a_ = {a_.x * coefficient - center.x * (coefficient - 1), a_.y * coefficient - center.y * (coefficient - 1)};
  b_ = {b_.x * coefficient - center.x * (coefficient - 1), b_.y * coefficient - center.y * (coefficient - 1)};
  c_ = {c_.x * coefficient - center.x * (coefficient - 1), c_.y * coefficient - center.y * (coefficient - 1)};
}

baeva::point_t baeva::Triangle::getA() const noexcept
{
  return a_;
}

baeva::point_t baeva::Triangle::getB() const noexcept
{
  return b_;
}

baeva::point_t baeva::Triangle::getC() const noexcept
{
  return c_;
}

std::ostream &baeva::Triangle::printInfo(std::ostream &out) const
{
  out << "A: (" << a_.x << ", " << a_.y << ")\n" << "B: (" << b_.x << ", " << b_.y << ")\n"
      << "C: (" << c_.x << ", " << c_.y << ")\n" << "center_: (" << (a_.x + b_.x + c_.x) / 3.0 << ", "
      << (a_.y + b_.y + c_.y) / 3.0 << ")\n";
  return out;
}
