#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iosfwd>

namespace baeva
{
  struct point_t;
  struct rectangle_t;

  class Shape
  {
  public:
    virtual ~Shape() = default;

    virtual double getArea() const noexcept = 0;

    virtual rectangle_t getFrameRect() const noexcept = 0;

    virtual void move(const point_t &newCenter) noexcept = 0;

    virtual void move(double shiftX, double shiftY) noexcept = 0;

    virtual std::ostream& printInfo(std::ostream &out) const = 0;

    virtual void scale(double coefficient) = 0;

    friend std::ostream &operator<<(std::ostream &out, const Shape &shape)
    {
      return shape.printInfo(out);
    }
  };
}

#endif //SHAPE_HPP
