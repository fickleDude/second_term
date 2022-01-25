#include <stdexcept>
#include <string>
#include <sstream>
#include <iostream>

#include <boost/test/unit_test.hpp>

void changeContainer(std::istream& in, std::ostream& out = std::cout);

BOOST_AUTO_TEST_SUITE(testChangeContainer)

std::string inputWithOne("1 2 3 4 5 6 7 8 9 1 0");
std::string inputWithTwo("1 2 3 4 5 6 7 8 9 2 0");
std::string inputWithNoChange("1 2 3 4 5 6 7 8 9 0");

BOOST_AUTO_TEST_CASE(testEmptyInput)
{
  std::string input("");

  std::istringstream in(input);

  BOOST_CHECK_NO_THROW(changeContainer(in));
}

BOOST_AUTO_TEST_CASE(testInvalidInputWithWrongCharacter)
{
  std::string input("23 abd 45 67 0");
  std::istringstream in(input);

  BOOST_CHECK_THROW(changeContainer(in), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(testInvalidInputWithoutZero)
{
  std::string input("23 45 67");
  std::istringstream in(input);

  BOOST_CHECK_THROW(changeContainer(in), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(testInputWithOne)
{
  std::string input("1 2 3 4 5 6 7 8 9 1 0");
  std::string output("1 3 5 7 9 1 \n");
  std::istringstream in(input);
  std::ostringstream out;

  BOOST_CHECK_NO_THROW(changeContainer(in, out));
  BOOST_CHECK(out.str() == output);
}

BOOST_AUTO_TEST_CASE(testInputWithTwo)
{
  std::string input("1 2 3 4 5 6 7 8 9 2 0");
  std::string output("1 2 3 1 1 1 4 5 6 1 1 1 7 8 9 1 1 1 2 \n");
  std::istringstream in(input);
  std::ostringstream out;

  BOOST_CHECK_NO_THROW(changeContainer(in, out));
  BOOST_CHECK(out.str() == output);
}

BOOST_AUTO_TEST_CASE(testInputWithNoChange)
{
  std::string input("1 2 3 4 5 6 7 8 9 0");
  std::string output("1 2 3 4 5 6 7 8 9 \n");
  std::istringstream in(input);
  std::ostringstream out;

  BOOST_CHECK_NO_THROW(changeContainer(in, out));
  BOOST_CHECK(out.str() == output);
}

BOOST_AUTO_TEST_SUITE_END()
