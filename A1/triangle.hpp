#ifndef A1_TRIANGLE_HPP
#define A1_TRIANGLE_HPP

#include "shape.hpp"
#include "base-types.hpp"

class Triangle : public Shape
{
public:

  Triangle(const point_t &a, const point_t &b, const point_t &c);

  double getArea() const override;

  rectangle_t getFrameRect() const override;

  void move(const point_t &newCenter) override;

  void move(double shiftX, double shiftY) override;

  std::ostream& printInfo(std::ostream &out) const override;

protected:
  point_t a_;
  point_t b_;
  point_t c_;
};

#endif //A1_TRIANGLE_HPP
