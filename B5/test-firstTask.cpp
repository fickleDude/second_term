#include <sstream>
#include <string>
#include <boost/test/unit_test.hpp>

void firstTask(std::istream &in, std::ostream &out);

const std::string INPUT = "welcome\n  to\t the\n\t internet\t\n have a\t look\n around";
const std::string OUTPUT = "a\naround\nhave\ninternet\nlook\nthe\nto\nwelcome\n";
const std::string EMPTY_INPUT = "";

BOOST_AUTO_TEST_SUITE(testFirstTask)

BOOST_AUTO_TEST_CASE(testCorrectInput)
{
  std::istringstream in(INPUT);
  std::ostringstream out;

  BOOST_CHECK_NO_THROW(firstTask(in, out));
}

BOOST_AUTO_TEST_CASE(testCorrectOutput)
{
  std::istringstream in(INPUT);
  std::ostringstream out;

  firstTask(in, out);

  BOOST_CHECK_EQUAL(out.str(), OUTPUT);
}

BOOST_AUTO_TEST_CASE(testEmptyInput)
{
  std::istringstream in(EMPTY_INPUT);
  std::ostringstream out;

  BOOST_CHECK_NO_THROW(firstTask(in, out));
  BOOST_CHECK(out.str() == "");
}

BOOST_AUTO_TEST_SUITE_END()
