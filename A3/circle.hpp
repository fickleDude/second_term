#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <iosfwd>
#include "shape.hpp"
#include "base-types.hpp"

namespace baeva
{
  class Circle : public Shape
  {
  public:

    Circle(double r, const point_t &center);

    double getArea() const noexcept override;

    rectangle_t getFrameRect() const noexcept override;

    void move(const point_t &newCenter) noexcept override;

    void move(double shiftX, double shiftY) noexcept override;

    point_t getCenter() const noexcept;

    double getRadius() const noexcept;

    void scale(double coefficient) override;

    std::ostream &printInfo(std::ostream &out) const override;

  protected:
    double r_;
    point_t center_;
  };
}

#endif //CIRCLE_HPP
