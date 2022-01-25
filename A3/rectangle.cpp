#include "rectangle.hpp"
#include <stdexcept>
#include <ostream>

baeva::Rectangle::Rectangle(double width, double height, const point_t &center) :
  width_(width),
  height_(height),
  center_(center)
{
  if ((width <= 0) || (height <= 0))
  {
    throw std::invalid_argument("Wrong parameters");
  }
};

double baeva::Rectangle::getArea() const noexcept
{
  return width_ * height_;
}

baeva::rectangle_t baeva::Rectangle::getFrameRect() const noexcept
{
  return baeva::rectangle_t{width_, height_, center_};
}

void baeva::Rectangle::move(const point_t &newCenter) noexcept
{
  center_ = newCenter;
}

void baeva::Rectangle::move(double shiftX, double shiftY) noexcept
{
  center_.x += shiftX;
  center_.y += shiftY;
}

baeva::point_t baeva::Rectangle::getCenter() const noexcept
{
  return center_;
}

double baeva::Rectangle::getWidth() const noexcept
{
  return width_;
}

double baeva::Rectangle::getHeight() const noexcept
{
  return height_;
}

void baeva::Rectangle::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Wrong coefficient");
  }
  width_ *= coefficient;
  height_ *= coefficient;
}

std::ostream &baeva::Rectangle::printInfo(std::ostream &out) const
{
  out << "width = " << width_ << " height = " << height_ << " center_: (" << center_.x << ", " << center_.y
      << ")\n";
  return out;
}
