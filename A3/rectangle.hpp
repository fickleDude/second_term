#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <iosfwd>
#include "shape.hpp"
#include "base-types.hpp"

namespace baeva
{
  class Rectangle : public Shape
  {
  public:

    Rectangle(double width, double height, const point_t &center);

    double getArea() const noexcept override;

    rectangle_t getFrameRect() const noexcept override;

    void move(const point_t &newCenter) noexcept override;

    void move(double shiftX, double shiftY) noexcept override;

    point_t getCenter() const noexcept;

    double getWidth() const noexcept;

    double getHeight() const noexcept;

    void scale(double coefficient) override;

    std::ostream& printInfo(std::ostream &out) const override;

  protected:
    double width_;
    double height_;
    point_t center_;
  };
}


#endif //RECTANGLE_HPP
