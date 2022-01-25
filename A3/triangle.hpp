#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <iosfwd>
#include "shape.hpp"
#include "base-types.hpp"

namespace baeva
{
  class Triangle : public Shape
  {
  public:

    Triangle(const point_t &a, const point_t &b, const point_t &c);

    double getArea() const noexcept override;

    rectangle_t getFrameRect() const noexcept override;

    void move(const point_t &newCenter) noexcept override;

    void move(double shiftX, double shiftY) noexcept override;

    void scale(double coefficient) override;

    point_t getA() const noexcept;

    point_t getB() const noexcept;

    point_t getC() const noexcept;

    std::ostream &printInfo(std::ostream &out) const override;

  protected:
    point_t a_;
    point_t b_;
    point_t c_;
  };
}

#endif //TRIANGLE_HPP
