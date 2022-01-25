#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <iosfwd>
#include <memory>
#include "shape.hpp"

namespace baeva
{
  class CompositeShape : public Shape
  {
  public:
    CompositeShape() noexcept;

    CompositeShape(const CompositeShape &compositeShape);

    CompositeShape(CompositeShape &&compositeShape) noexcept;

    ~CompositeShape() noexcept = default;

    CompositeShape &operator=(const CompositeShape &compositeShape);

    CompositeShape &operator=(CompositeShape &&compositeShape) noexcept;

    std::shared_ptr<Shape> operator[](unsigned int index) const;

    void addShape(const std::shared_ptr<Shape> &shape);

    void removeFromEnd();

    void removeShape(unsigned int index);

    void clearShape();

    std::shared_ptr<Shape> top() const;

    unsigned int getSize() const noexcept;

    unsigned int getCapacity() const noexcept;

    double getArea() const noexcept override;

    rectangle_t getFrameRect() const noexcept override;

    void move(const point_t &newCenter) noexcept override;

    void move(double shiftX, double shiftY) noexcept override;

    std::ostream &printInfo(std::ostream &out) const override;

    void scale(double coefficient) override;

  private:
    unsigned int size_;
    unsigned int capacity_;
    std::unique_ptr<std::shared_ptr<Shape>[]> array_;
  };
}

#endif
