#include <sstream>
#include <string>

#include <boost/test/unit_test.hpp>
#include "shape.hpp"

BOOST_AUTO_TEST_SUITE(testShape)

const Shape TRIANGLE = {{0, 0},{5, 2},{4, 5}};
const Shape RECTANGLE = {{-1,  2},{-1,  7},{-10, 2},{-10, 7}};
const Shape PARALLELOGRAM = {{1, 7},{4, 5},{4, 7},{1, 9}};
const Shape SQUARE = {{8,  4},{8,  8},{12, 8},{12, 4}};
const Shape PENTAGON = {{-4, 1},{-2, 4},{2,  5},{5,  2},{0,  -3}};

const Point POINT1 = {0, 0};
const Point POINT2 = {4, 5};
const size_t DISTANCE = 41;

BOOST_AUTO_TEST_CASE(testIsTriangle)
{
  BOOST_CHECK(isTriangle(TRIANGLE));
  BOOST_CHECK(!isTriangle(SQUARE));
  BOOST_CHECK(!isTriangle(RECTANGLE));
}

BOOST_AUTO_TEST_CASE(testIsRectangle)
{
  BOOST_CHECK(isRectangle(RECTANGLE));
  BOOST_CHECK(isRectangle(SQUARE));
  BOOST_CHECK(!isRectangle(TRIANGLE));
  BOOST_CHECK(!isRectangle(PARALLELOGRAM));
}

BOOST_AUTO_TEST_CASE(testIsSquare)
{
  BOOST_CHECK(isSquare(SQUARE));
  BOOST_CHECK(!isSquare(TRIANGLE));
  BOOST_CHECK(!isSquare(RECTANGLE));
  BOOST_CHECK(!isRectangle(PARALLELOGRAM));
  BOOST_CHECK(!isSquare(PENTAGON));
}

BOOST_AUTO_TEST_CASE(testSquareDistance)
{
  BOOST_CHECK_EQUAL(getSquareDistance(POINT1, POINT2), DISTANCE);
}

BOOST_AUTO_TEST_CASE(ShapeComparatorTest)
{
  BOOST_CHECK(TRIANGLE < RECTANGLE);
  BOOST_CHECK(TRIANGLE < SQUARE);
  BOOST_CHECK(SQUARE < RECTANGLE);
}

BOOST_AUTO_TEST_SUITE_END()
