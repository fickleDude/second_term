#ifndef A1_CIRCLE_HPP
#define A1_CIRCLE_HPP

#include "shape.hpp"
#include "base-types.hpp"

class Circle : public Shape
{
public:

  Circle(double r, const point_t &center);

  double getArea() const override;

  rectangle_t getFrameRect() const override;

  void move(const point_t &newCenter) override;

  void move(double shiftX, double shiftY) override;

  std::ostream& printInfo(std::ostream &out) const override;

protected:
  double r_;
  point_t center_;
};

#endif //A1_CIRCLE_HPP
