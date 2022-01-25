#include <stdexcept>
#include <boost/test/unit_test.hpp>
#include <boost/test/tools/floating_point_comparison.hpp>

#include "rectangle.hpp"

BOOST_AUTO_TEST_SUITE(testRectangle)

const baeva::point_t CENTER{1.3, -5.9};
const double WIDTH = 3.5;
const double HEIGHT = 3.5;
double SHIFT_X = 1.9;
double SHIFT_Y = -2.8;
baeva::point_t NEW_CENTER = {12.8, -10.2};
double COEFFICIENT = 5.7;
const double PRECISION = 1e-8;

BOOST_AUTO_TEST_CASE(testDefaultConstructor)
{
  BOOST_CHECK_NO_THROW(baeva::Rectangle(WIDTH, HEIGHT, CENTER));
}

BOOST_AUTO_TEST_CASE(testConstructorWithNegativeParameters)
{
  BOOST_CHECK_THROW(baeva::Rectangle(-WIDTH, HEIGHT, CENTER), std::invalid_argument);
  BOOST_CHECK_THROW(baeva::Rectangle(WIDTH, -HEIGHT, CENTER), std::invalid_argument);
  BOOST_CHECK_THROW(baeva::Rectangle(-WIDTH, -HEIGHT, CENTER), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testConstructorWithZeroParameters)
{
  BOOST_CHECK_THROW(baeva::Rectangle(0.0, HEIGHT, CENTER), std::invalid_argument);
  BOOST_CHECK_THROW(baeva::Rectangle(WIDTH, 0.0, CENTER), std::invalid_argument);
  BOOST_CHECK_THROW(baeva::Rectangle(0.0, 0.0, CENTER), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testGetCenter)
{
  baeva::Rectangle rectangle(WIDTH, HEIGHT, CENTER);

  BOOST_CHECK_CLOSE(rectangle.getCenter().x, CENTER.x, PRECISION);
  BOOST_CHECK_CLOSE(rectangle.getCenter().y, CENTER.y, PRECISION);
}

BOOST_AUTO_TEST_CASE(testGetWight)
{
  baeva::Rectangle rectangle(WIDTH, HEIGHT, CENTER);

  BOOST_CHECK_CLOSE(rectangle.getWidth(), WIDTH, PRECISION);
}

BOOST_AUTO_TEST_CASE(testGetHeight)
{
  baeva::Rectangle rectangle(WIDTH, HEIGHT, CENTER);

  BOOST_CHECK_CLOSE(rectangle.getHeight(), HEIGHT, PRECISION);
}

BOOST_AUTO_TEST_CASE(testGetArea)
{
  baeva::Rectangle rectangle(WIDTH, HEIGHT, CENTER);
  double expectedArea = WIDTH * HEIGHT;

  BOOST_CHECK_CLOSE(rectangle.getArea(), expectedArea, PRECISION);
}

BOOST_AUTO_TEST_CASE(testGetFrameRect)
{
  baeva::Rectangle rectangle(WIDTH, HEIGHT, CENTER);
  baeva::rectangle_t expectedFrameRect{ WIDTH, HEIGHT, CENTER };

  BOOST_CHECK_CLOSE(rectangle.getFrameRect().width, expectedFrameRect.width, PRECISION);
  BOOST_CHECK_CLOSE(rectangle.getFrameRect().height, expectedFrameRect.height, PRECISION);
  BOOST_CHECK_CLOSE(rectangle.getFrameRect().pos.x, expectedFrameRect.pos.x, PRECISION);
  BOOST_CHECK_CLOSE(rectangle.getFrameRect().pos.y, expectedFrameRect.pos.y, PRECISION);
}

BOOST_AUTO_TEST_CASE(testMoveToPosition)
{
  baeva::Rectangle rectangle(WIDTH, HEIGHT, CENTER);

  rectangle.move(NEW_CENTER);

  BOOST_CHECK_CLOSE(rectangle.getCenter().x, NEW_CENTER.x, PRECISION);
  BOOST_CHECK_CLOSE(rectangle.getCenter().y, NEW_CENTER.y, PRECISION);
}

BOOST_AUTO_TEST_CASE(testUnchangedAreaAfterMoveToPosition)
{
  baeva::Rectangle rectangle(WIDTH, HEIGHT, CENTER);
  double expectedArea = rectangle.getArea();

  rectangle.move(NEW_CENTER);

  BOOST_CHECK_CLOSE(rectangle.getArea(), expectedArea, PRECISION);
}

BOOST_AUTO_TEST_CASE(testRectangleMoveBy)
{
  baeva::Rectangle rectangle(WIDTH, HEIGHT, CENTER);
  baeva::point_t expectedCenter{ rectangle.getCenter().x + SHIFT_X, rectangle.getCenter().y + SHIFT_Y };

  rectangle.move(SHIFT_X, SHIFT_Y);

  BOOST_CHECK_CLOSE(expectedCenter.x, rectangle.getCenter().x, PRECISION);
  BOOST_CHECK_CLOSE(expectedCenter.y, rectangle.getCenter().y, PRECISION);
}

BOOST_AUTO_TEST_CASE(testUnchangedAreaAfterMoveBy)
{
  baeva::Rectangle rectangle(WIDTH, HEIGHT, CENTER);
  double expectedArea = rectangle.getArea();

  rectangle.move(SHIFT_X, SHIFT_Y);

  BOOST_CHECK_CLOSE(rectangle.getArea(), expectedArea, PRECISION);
}

BOOST_AUTO_TEST_CASE(testUnchangedCenterAfterScale)
{
  baeva::Rectangle rectangle(WIDTH, HEIGHT, CENTER);
  baeva::point_t expectedCenter = rectangle.getCenter();

  rectangle.scale(COEFFICIENT);

  BOOST_CHECK_CLOSE(rectangle.getCenter().x, expectedCenter.x, PRECISION);
  BOOST_CHECK_CLOSE(rectangle.getCenter().y, expectedCenter.y, PRECISION);
}

BOOST_AUTO_TEST_CASE(testAreaAfterScale)
{
  baeva::Rectangle rectangle(WIDTH, HEIGHT, CENTER);
  double expectedArea = rectangle.getArea() * std::pow(COEFFICIENT, 2);

  rectangle.scale(COEFFICIENT);

  BOOST_CHECK_CLOSE(rectangle.getArea(), expectedArea, PRECISION);
}

BOOST_AUTO_TEST_CASE(testScaleWithZeroCoefficient)
{
  baeva::Rectangle rectangle(WIDTH, HEIGHT, CENTER);

  BOOST_CHECK_THROW(rectangle.scale(0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testScaleWithNegativeCoefficient)
{
  baeva::Rectangle rectangle(WIDTH, HEIGHT, CENTER);

  BOOST_CHECK_THROW(rectangle.scale(-2), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
