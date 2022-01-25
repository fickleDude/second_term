#ifndef A1_RECTANGLE_HPP
#define A1_RECTANGLE_HPP

#include "shape.hpp"
#include "base-types.hpp"

class Rectangle : public Shape
{
public:

  Rectangle(double width, double height, const point_t &center);

  double getArea() const override;

  rectangle_t getFrameRect() const override;

  void move(const point_t &newCenter) override;

  void move(double shiftX, double shiftY) override;

  std::ostream& printInfo(std::ostream &out) const override;

protected:
  double width_;
  double height_;
  point_t center_;
};

#endif //A1_RECTANGLE_HPP
