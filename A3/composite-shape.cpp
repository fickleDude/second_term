#include "composite-shape.hpp"
#include <cstdlib>
#include <cmath>
#include <stdexcept>
#include <ostream>
#include <algorithm>
#include "base-types.hpp"

baeva::CompositeShape::CompositeShape() noexcept:
  size_(0),
  capacity_(0),
  array_(nullptr)
{}

baeva::CompositeShape::CompositeShape(const baeva::CompositeShape &src) :
  size_(src.size_),
  capacity_(src.capacity_),
  array_(std::make_unique<std::shared_ptr<Shape>[]>(src.capacity_))
{
  for (unsigned int i = 0; i < size_; ++i)
  {
    array_[i] = src.array_[i];
  }
}

baeva::CompositeShape::CompositeShape(baeva::CompositeShape &&src) noexcept:
  size_(src.size_),
  capacity_(src.capacity_),
  array_(std::move(src.array_))
{
  src.size_ = 0;
  src.capacity_ = 0;
}

baeva::CompositeShape &baeva::CompositeShape::operator=(const baeva::CompositeShape &src)
{
  if (this != &src)
  {
    size_ = src.size_;
    capacity_ = src.capacity_;
    array_ = std::make_unique<std::shared_ptr<Shape>[]>(src.capacity_);
    for (unsigned int i = 0; i < size_; ++i)
    {
      array_[i] = src.array_[i];
    }
  }
  return *this;
}

baeva::CompositeShape &baeva::CompositeShape::operator=(baeva::CompositeShape &&src) noexcept
{
  if (this != &src)
  {
    size_ = src.size_;
    capacity_ = src.capacity_;
    array_ = std::move(src.array_);
    src.size_ = 0;
    src.capacity_ = 0;
  }
  return *this;
}

std::shared_ptr<baeva::Shape> baeva::CompositeShape::operator[](unsigned int index) const
{
  if (size_ == 0)
  {
    throw std::underflow_error("CompositeShape is empty");
  }
  if (size_ <= index)
  {
    throw std::out_of_range("Index is out of range");
  }
  return array_[index];
}

void baeva::CompositeShape::addShape(const std::shared_ptr<baeva::Shape> &newShape)
{
  if (newShape == nullptr)
  {
    throw std::invalid_argument("Wrong shape parameter");
  }
  if (size_ == 0)
  {
    std::unique_ptr<std::shared_ptr<Shape>[]> temp(std::make_unique<std::shared_ptr<Shape>[]>(++capacity_));
    temp[size_++] = newShape;
    array_.swap(temp);
  } else if (capacity_ > size_)
  {
    array_[size_++] = newShape;
  } else
  {
    std::unique_ptr<std::shared_ptr<Shape>[]> temp(std::make_unique<std::shared_ptr<Shape>[]>(capacity_ * 2));
    capacity_ *= 2;
    for (unsigned int i = 0; i < size_; i++)
    {
      temp[i] = array_[i];
    }
    temp[size_++] = newShape;
    array_.swap(temp);
  }
}

unsigned int baeva::CompositeShape::getSize() const noexcept
{
  return size_;
}

unsigned int baeva::CompositeShape::getCapacity() const noexcept
{
  return capacity_;
}

void baeva::CompositeShape::removeFromEnd()
{
  if (size_ == 0)
  {
    throw std::underflow_error("CompositeShape is empty");
  }
  array_[--size_] = nullptr;
}

void baeva::CompositeShape::removeShape(unsigned int index)
{
  if (size_ == 0)
  {
    throw std::underflow_error("CompositeShape is empty");
  }
  if (size_ <= index)
  {
    throw std::out_of_range("Index is out of range");
  }
  for (unsigned int i = index; i < size_ - 1; i++)
  {
    array_[i] = array_[i + 1];
  }
  array_[--size_] = nullptr;
}

void baeva::CompositeShape::clearShape()
{
  array_.reset();
  size_ = 0;
  capacity_ = 0;
}

std::shared_ptr<baeva::Shape> baeva::CompositeShape::top() const
{
  if (size_ == 0)
  {
    throw std::underflow_error("CompositeShape is empty");
  }
  return array_[size_ - 1];
}

double baeva::CompositeShape::getArea() const noexcept
{
  double area = 0.0;
  for (unsigned int i = 0; i < size_; i++)
  {
    area += array_[i]->getArea();
  }
  return area;
}

baeva::rectangle_t baeva::CompositeShape::getFrameRect() const noexcept
{
  if (size_ == 0)
  {
    return {0, 0, {std::numeric_limits<double>::signaling_NaN(),
                   std::numeric_limits<double>::signaling_NaN()}};
  }
  rectangle_t frameRect = array_[0]->getFrameRect();
  double minX = frameRect.pos.x - (frameRect.width / 2.0);
  double maxX = frameRect.pos.x + (frameRect.width / 2.0);
  double minY = frameRect.pos.y - (frameRect.height / 2.0);
  double maxY = frameRect.pos.y + (frameRect.height / 2.0);
  for (unsigned int i = 1; i < size_; i++)
  {
    frameRect = array_[i]->getFrameRect();
    minX = std::fmin(minX, frameRect.pos.x - (frameRect.width / 2.0));
    maxX = std::fmax(maxX, frameRect.pos.x + (frameRect.width / 2.0));
    minY = std::fmin(minY, frameRect.pos.y - (frameRect.height / 2.0));
    maxY = std::fmax(maxY, frameRect.pos.y + (frameRect.height / 2.0));
  }
  frameRect.width = maxX - minX;
  frameRect.height = maxY - minY;
  frameRect.pos = {(minX + frameRect.width / 2.0), (minY + frameRect.height / 2.0)};
  return frameRect;
}

void baeva::CompositeShape::move(const baeva::point_t &newCenter) noexcept
{
  move(newCenter.x - getFrameRect().pos.x, newCenter.y - getFrameRect().pos.y);
}

void baeva::CompositeShape::move(double shiftX, double shiftY) noexcept
{
  for (unsigned int i = 0; i < size_; i++)
  {
    array_[i]->move(shiftX, shiftY);
  }
}

std::ostream &baeva::CompositeShape::printInfo(std::ostream &out) const
{
  if (size_ > 0)
  {
    const rectangle_t rect = getFrameRect();
    out << "Composite shape:\n";
    out << "Center of composite shape: " << rect.pos.x << ", " << rect.pos.y << "\n";
    out << "Count of shapes: " << capacity_ << "\n";
    out << "Frame rect: \n";
    out << "Width: " << rect.width << "\n";
    out << "Height: " << rect.height << "\n";
    out << "Area of composite shape: " << getArea() << "\n\n";
  } else
  {
    out << "Composite shape is empty.\n";
  }
  return out;
}

void baeva::CompositeShape::scale(double coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Wrong coefficient");
  }
  point_t compositeShapeCenter = getFrameRect().pos;
  for (unsigned int i = 0; i < size_; i++)
  {
    double dx = (array_[i]->getFrameRect().pos.x - compositeShapeCenter.x) * (coefficient - 1);
    double dy = (array_[i]->getFrameRect().pos.y - compositeShapeCenter.y) * (coefficient - 1);
    array_[i]->move(dx, dy);
    array_[i]->scale(coefficient);
  }
}
