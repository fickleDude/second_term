#include <sstream>
#include <string>

#include <boost/test/unit_test.hpp>

void secondTask(std::istream &in, std::ostream &out);

BOOST_AUTO_TEST_SUITE(testSecondTask)

const std::string INPUT = "4 (5;5) (7;5) (7;6) (5;6)\n4 (10; 10) (10; 11) (11; 11) (11; 10)\n"
                          "3 (1;1) (2;2) (3;1)\n5 (-7;9) (4;7) (-6;8) (10;11) (13;-2)";
const std::string OUTPUT = "Vertices: 16\nTriangles: 1\nSquares: 1\nRectangles: 2\n"
                           "Points: (5;5) (10;10) (1;1) \nShapes:\n3 (1;1) (2;2) (3;1) \n"
                           "4 (10;10) (10;11) (11;11) (11;10) \n4 (5;5) (7;5) (7;6) (5;6) \n";
const std::string EMPTY_INPUT = "";
const std::string EMPTY_OUTPUT = "Vertices: 0\nTriangles: 0\nSquares: 0\nRectangles: 0\nPoints: \nShapes:\n";

BOOST_AUTO_TEST_CASE(testCorrectTaskTwo)
{
  std::istringstream in(INPUT);
  std::ostringstream out;

  BOOST_CHECK_NO_THROW(secondTask(in, out));
  BOOST_CHECK_EQUAL(out.str(), OUTPUT);
}

BOOST_AUTO_TEST_CASE(testEmptyInput)
{
  std::istringstream in(EMPTY_INPUT);
  std::ostringstream out;

  BOOST_CHECK_NO_THROW(secondTask(in, out));
  BOOST_CHECK_EQUAL(out.str(), EMPTY_OUTPUT);
}

BOOST_AUTO_TEST_SUITE_END()
