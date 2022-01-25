#define _USE_MATH_DEFINES

#include <cmath>
#include <stdexcept>
#include <boost/test/unit_test.hpp>
#include <boost/test/tools/floating_point_comparison.hpp>

#include "circle.hpp"

BOOST_AUTO_TEST_SUITE(testCircle)

const baeva::point_t CENTER{1.3, -5.9};
const double RADIUS = 3.5;
double SHIFT_X = 10;
double SHIFT_Y = -2;
baeva::point_t NEW_CENTER = {2.8, -1.2};
double COEFFICIENT = 1.5;
const double PRECISION = 1e-8;

BOOST_AUTO_TEST_CASE(testDefaultConstructor)
{
  BOOST_CHECK_NO_THROW(baeva::Circle(RADIUS, CENTER));
}

BOOST_AUTO_TEST_CASE(testConstructorWithZeroRadius)
{
  BOOST_CHECK_THROW(baeva::Circle(0.0, CENTER), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testConstructorWithNegativeRadius)
{
  BOOST_CHECK_THROW(baeva::Circle(-RADIUS, CENTER), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testGetRadius)
{
  baeva::Circle circle(RADIUS, CENTER);

  BOOST_CHECK_CLOSE(circle.getRadius(), RADIUS, PRECISION);
}

BOOST_AUTO_TEST_CASE(testGetCenter)
{
  baeva::Circle circle(RADIUS, CENTER);

  BOOST_CHECK_CLOSE(circle.getCenter().x, CENTER.x, PRECISION);
  BOOST_CHECK_CLOSE(circle.getCenter().y, CENTER.y, PRECISION);
}

BOOST_AUTO_TEST_CASE(testGetArea)
{
  baeva::Circle circle(RADIUS, CENTER);
  double expectedArea = std::pow(RADIUS, 2) * M_PI;

  BOOST_CHECK_CLOSE(circle.getArea(), expectedArea, PRECISION);
}

BOOST_AUTO_TEST_CASE(testGetFrameRect)
{
  baeva::Circle circle(RADIUS, CENTER);
  baeva::rectangle_t expectedFrameRect{ RADIUS * 2, RADIUS * 2, CENTER };

  BOOST_CHECK_CLOSE(circle.getFrameRect().width, expectedFrameRect.width, PRECISION);
  BOOST_CHECK_CLOSE(circle.getFrameRect().height, expectedFrameRect.height, PRECISION);
  BOOST_CHECK_CLOSE(circle.getFrameRect().pos.x, expectedFrameRect.pos.x, PRECISION);
  BOOST_CHECK_CLOSE(circle.getFrameRect().pos.y, expectedFrameRect.pos.y, PRECISION);
}

BOOST_AUTO_TEST_CASE(testMoveToPosition)
{
  baeva::Circle circle(RADIUS, CENTER);

  circle.move(NEW_CENTER);

  BOOST_CHECK_CLOSE(circle.getCenter().x, NEW_CENTER.x, PRECISION);
  BOOST_CHECK_CLOSE(circle.getCenter().y, NEW_CENTER.y, PRECISION);
}

BOOST_AUTO_TEST_CASE(testUnchangedAreaAfterMoveToPosition)
{
  baeva::Circle circle(RADIUS, CENTER);
  double expectedArea = circle.getArea();

  circle.move(NEW_CENTER);

  BOOST_CHECK_CLOSE(circle.getArea(), expectedArea, PRECISION);
}

BOOST_AUTO_TEST_CASE(testMoveBy)
{
  baeva::Circle circle(RADIUS, CENTER);
  baeva::point_t expectedCenter{ circle.getCenter().x + SHIFT_X, circle.getCenter().y + SHIFT_Y };

  circle.move(SHIFT_X, SHIFT_Y);

  BOOST_CHECK_CLOSE(expectedCenter.x, circle.getCenter().x, PRECISION);
  BOOST_CHECK_CLOSE(expectedCenter.y, circle.getCenter().y, PRECISION);
}

BOOST_AUTO_TEST_CASE(testUnchangedAreaAfterMoveBy)
{
  baeva::Circle circle(RADIUS, CENTER);
  double expectedArea = circle.getArea();

  circle.move(SHIFT_X, SHIFT_Y);

  BOOST_CHECK_CLOSE(circle.getArea(), expectedArea, PRECISION);
}

BOOST_AUTO_TEST_CASE(testUnchangedCenterAfterScale)
{
  baeva::Circle circle(RADIUS, CENTER);
  baeva::point_t expectedCenter = circle.getCenter();

  circle.scale(COEFFICIENT);

  BOOST_CHECK_CLOSE(circle.getCenter().x, expectedCenter.x, PRECISION);
  BOOST_CHECK_CLOSE(circle.getCenter().y, expectedCenter.y, PRECISION);
}

BOOST_AUTO_TEST_CASE(testAreaAfterScale)
{
  baeva::Circle circle(RADIUS, CENTER);
  double expectedArea = circle.getArea() * std::pow(COEFFICIENT, 2);

  circle.scale(COEFFICIENT);

  BOOST_CHECK_CLOSE(circle.getArea(), expectedArea, PRECISION);
}

BOOST_AUTO_TEST_CASE(testScaleWithZeroCoefficient)
{
  baeva::Circle circle(RADIUS, CENTER);

  BOOST_CHECK_THROW(circle.scale(0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testScaleWithNegativeCoefficient)
{
  baeva::Circle circle(RADIUS, CENTER);

  BOOST_CHECK_THROW(circle.scale(-2), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
