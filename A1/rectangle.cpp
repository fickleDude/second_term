#include "rectangle.hpp"
#include <stdexcept>

Rectangle::Rectangle(double width, double height, const point_t &center) :
  width_(width),
  height_(height),
  center_(center)
{
  if ((width <= 0) || (height <= 0))
  {
    throw std::invalid_argument("Wrong parameters");
  }
};

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rectangle_t{width_, height_, center_};
}

void Rectangle::move(const point_t &newCenter)
{
  center_ = newCenter;
}

void Rectangle::move(double shiftX, double shiftY)
{
  center_.x += shiftX;
  center_.y += shiftY;
}

std::ostream& Rectangle::printInfo(std::ostream &out) const
{
  out << "width = " << width_ << " height = " << height_ << " center_: (" << center_.x << ", " << center_.y
      << ")\n";
  return out;
}
