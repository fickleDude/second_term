#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"
#include "composite-shape.hpp"

using namespace baeva;

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

  CompositeShape compositeShape;
  std::cout << compositeShape;
  compositeShape.addShape(std::make_shared<Rectangle>(rectangle));
  compositeShape.addShape(std::make_shared<Triangle>(triangle));
  compositeShape.addShape(std::make_shared<Circle>(circle));
  std::cout << compositeShape;
  std::cout << compositeShape.getCapacity() << "\n";
  std::cout << compositeShape.getSize() << "\n";
  std::cout << compositeShape.getArea() << "\n";
  rectangle_t frameRect = compositeShape.getFrameRect();
  std::cout << "width = " << frameRect.width << " height = " << frameRect.height <<
            " center_: (" << frameRect.pos.x << ", " << frameRect.pos.y << ")\n";
  compositeShape.move(MOVE_POINT);
  compositeShape.move(-6.7, 4.5);
  compositeShape.scale(3.1);
  compositeShape.removeShape(0);
  compositeShape.removeFromEnd();
  compositeShape.clearShape();
  return 0;
}

void testMethods(Shape &shape)
{
  std::cout << shape;
  shape.getArea();
  shape.move(MOVE_POINT);
  shape.move(-6.7, 4.5);
  shape.scale(2);
}
