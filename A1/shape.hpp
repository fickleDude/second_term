#ifndef A1_SHAPE_HPP
#define A1_SHAPE_HPP

#include <ostream>

struct point_t;
struct rectangle_t;

class Shape
{
public:
  virtual ~Shape() = default;

  virtual double getArea() const = 0;

  virtual rectangle_t getFrameRect() const = 0;

  virtual void move(const point_t &newCenter) = 0;

  virtual void move(double shiftX, double shiftY) = 0;

  virtual std::ostream& printInfo(std::ostream &out) const = 0;

  friend std::ostream& operator<<(std::ostream &out, const Shape &shape)
  {
    return shape.printInfo(out);
  }
};

#endif //A1_SHAPE_HPP
