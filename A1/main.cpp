#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"

const point_t MOVE_POINT{-2.5, 3.5};

void testMethods(Shape &shape);

int main()
{
  Rectangle rectangle(1.5, 3.5, {-0.5, 2.5});
  Circle circle(7.6, {3.4, -9.8});
  Triangle triangle({1.5, -0.5}, {2.5, -1.5}, {5.0, 1.0});
  testMethods(rectangle);
  testMethods(circle);
  testMethods(triangle);
  return 0;
}

void testMethods(Shape &shape)
{
  std::cout << shape;
  shape.getArea();
  shape.move(MOVE_POINT);
  shape.move(-6.7, 4.5);
}
