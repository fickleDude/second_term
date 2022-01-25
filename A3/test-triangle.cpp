#define _USE_MATH_DEFINES

#include <cmath>
#include <stdexcept>
#include <boost/test/unit_test.hpp>
#include <boost/test/tools/floating_point_comparison.hpp>

#include "triangle.hpp"

BOOST_AUTO_TEST_SUITE(testTriangle)

const baeva::point_t A{-3, 1.5};
const baeva::point_t B{-0.5, 4.5};
const baeva::point_t C{5.5, -0.5};
double SHIFT_X = 6.5;
double SHIFT_Y = -3.4;
baeva::point_t NEW_CENTER = {8.1, -1.2};
double COEFFICIENT = 1.2;
const double PRECISION = 1e-8;

BOOST_AUTO_TEST_CASE(testDefaultConstructor)
{
  BOOST_CHECK_NO_THROW(baeva::Triangle(A, B, C));
}

BOOST_AUTO_TEST_CASE(testNotExistingSideConstructor)
{
  BOOST_CHECK_THROW(baeva::Triangle({-1.0, 0.0}, {0.5, 0.5}, {2.0, 1.0}), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testGetArea)
{
  baeva::Triangle triangle(A, B, C);
  double expectedArea = (std::abs((A.x - C.x) * (B.y - C.y) - (B.x - C.x) * (A.y - C.y))) / 2.0;

  BOOST_CHECK_CLOSE(triangle.getArea(), expectedArea, PRECISION);
}

BOOST_AUTO_TEST_CASE(testGetFrameRect)
{
  baeva::Triangle triangle(A, B, C);
  baeva::rectangle_t expectedFrameRect{ 8.5, 5, {1.25, 2}};

  baeva::rectangle_t frameRect = triangle.getFrameRect();

  BOOST_CHECK_CLOSE(frameRect.width, expectedFrameRect.width, PRECISION);
  BOOST_CHECK_CLOSE(frameRect.height, expectedFrameRect.height, PRECISION);
  BOOST_CHECK_CLOSE(frameRect.pos.x, expectedFrameRect.pos.x, PRECISION);
  BOOST_CHECK_CLOSE(frameRect.pos.y, expectedFrameRect.pos.y, PRECISION);
}

BOOST_AUTO_TEST_CASE(testMoveToPosition)
{
  baeva::Triangle triangle(A, B, C);

  triangle.move(NEW_CENTER);
  baeva::point_t center{
    (triangle.getA().x + triangle.getB().x + triangle.getC().x) / 3.0,
        (triangle.getA().y + triangle.getB().y + triangle.getC().y) / 3.0};

  BOOST_CHECK_CLOSE(center.x, NEW_CENTER.x, PRECISION);
  BOOST_CHECK_CLOSE(center.y, NEW_CENTER.y, PRECISION);
}

BOOST_AUTO_TEST_CASE(testUnchangedAreaAfterMoveToPosition)
{
  baeva::Triangle triangle(A, B, C);
  double expectedArea = (std::abs((A.x - C.x) * (B.y - C.y) - (B.x - C.x) * (A.y - C.y))) / 2.0;

  triangle.move(NEW_CENTER);

  BOOST_CHECK_CLOSE(triangle.getArea(), expectedArea, PRECISION);
}

BOOST_AUTO_TEST_CASE(testMoveBy)
{
  baeva::Triangle triangle(A, B, C);
  baeva::point_t expectedCenter{((triangle.getA().x + triangle.getB().x + triangle.getC().x) / 3.0) + SHIFT_X,
        ((triangle.getA().y + triangle.getB().y + triangle.getC().y) / 3.0) + SHIFT_Y};

  triangle.move(SHIFT_X, SHIFT_Y);
  baeva::point_t newCenter{(triangle.getA().x + triangle.getB().x + triangle.getC().x) / 3.0,
        (triangle.getA().y + triangle.getB().y + triangle.getC().y) / 3.0};

  BOOST_CHECK_CLOSE(newCenter.x, expectedCenter.x, PRECISION);
  BOOST_CHECK_CLOSE(newCenter.y, expectedCenter.y, PRECISION);
}

BOOST_AUTO_TEST_CASE(testUnchangedAreaAfterMoveBy)
{
  baeva::Triangle triangle(A, B, C);
  double expectedArea = (std::abs((A.x - C.x) * (B.y - C.y) - (B.x - C.x) * (A.y - C.y))) / 2.0;

  triangle.move(SHIFT_X, SHIFT_Y);

  BOOST_CHECK_CLOSE(triangle.getArea(), expectedArea, PRECISION);
}

BOOST_AUTO_TEST_CASE(testUnchangedCenterAfterScale)
{
  baeva::Triangle triangle(A, B, C);
  baeva::point_t expectedCenter{ (A.x + B.x + C.x) / 3.0, (A.y + B.y + C.y) / 3.0 };

  triangle.scale(COEFFICIENT);
  baeva::point_t newCenter{(triangle.getA().x + triangle.getB().x + triangle.getC().x) / 3.0,
        (triangle.getA().y + triangle.getB().y + triangle.getC().y) / 3.0};

  BOOST_CHECK_CLOSE(newCenter.x, expectedCenter.x, PRECISION);
  BOOST_CHECK_CLOSE(newCenter.y, expectedCenter.y, PRECISION);
}

BOOST_AUTO_TEST_CASE(testAreaAfterScale)
{
  baeva::Triangle triangle(A, B, C);
  double expectedArea = ((std::abs((A.x - C.x) * (B.y - C.y) - (B.x - C.x) * (A.y - C.y))) / 2.0) * std::pow(COEFFICIENT, 2);

  triangle.scale(COEFFICIENT);

  BOOST_CHECK_CLOSE(triangle.getArea(), expectedArea, PRECISION);
}

BOOST_AUTO_TEST_CASE(testScaleWithZeroCoefficient)
{
  baeva::Triangle triangle(A, B, C);

  BOOST_CHECK_THROW(triangle.scale(0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testRectangleScaleWithNegativeCoefficient)
{
  baeva::Triangle triangle(A, B, C);

  BOOST_CHECK_THROW(triangle.scale(-2), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
