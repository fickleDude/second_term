#include <sstream>
#include <string>

#include <boost/test/unit_test.hpp>
#include "dataStruct.hpp"

BOOST_AUTO_TEST_SUITE(testDataStruct)

const DataStruct DATA = {-3, 2, "Pfizer"};
const DataStruct DATA1 = {1, 0, "Moderna"};
const DataStruct DATA2 = {1, 5, "Janssen"};
const DataStruct DATA3 = {1, 5, "AstraZeneca"};
const std::string INVALID_FIRST_KEY = "abc, 0, \"vaccine\"";
const std::string INVALID_RANGE_FIRST_KEY = "9, 0, \"vaccine\"";
const std::string INVALID_SECOND_KEY = "0, abc, \"vaccine\"";
const std::string INVALID_RANGE_SECOND_KEY = "0, -6, \"vaccine\"";
const std::string INVALID_INPUT_WITH_NO_COMMAS = "2 2 \"vaccine\"";
const std::string CORRECT_INPUT = "4, 1, SputnikV";
const std::string CORRECT_OUTPUT = "-4,3,SputnikV";
const DataStruct OUTPUT = {-4, 3, "SputnikV"};

BOOST_AUTO_TEST_CASE(testInvalidFirstKey)
{
  std::istringstream in(INVALID_FIRST_KEY);
  DataStruct data;
  in >> data;

  BOOST_CHECK(in.fail());
}

BOOST_AUTO_TEST_CASE(testInvalidRangeFirstKey)
{
  std::istringstream in(INVALID_RANGE_FIRST_KEY);
  DataStruct data;
  in >> data;

  BOOST_CHECK(in.fail());
}

BOOST_AUTO_TEST_CASE(testInvalidSecondKey)
{
  std::istringstream in(INVALID_SECOND_KEY);
  DataStruct data;
  in >> data;

  BOOST_CHECK(in.fail());
}

BOOST_AUTO_TEST_CASE(testInvalidRangeSecondKey)
{
  std::istringstream in(INVALID_RANGE_SECOND_KEY);
  DataStruct data;
  in >> data;

  BOOST_CHECK(in.fail());
}

BOOST_AUTO_TEST_CASE(testInvalidInputWithNoCommas)
{
  std::istringstream in(INVALID_INPUT_WITH_NO_COMMAS);
  DataStruct data;
  in >> data;

  BOOST_CHECK(in.fail());
}

BOOST_AUTO_TEST_CASE(testCorrectInput)
{
  std::istringstream in(CORRECT_INPUT);
  DataStruct data;
  in >> data;

  BOOST_CHECK(!in.fail());
}

BOOST_AUTO_TEST_CASE(testCorrectOutput)
{
  std::ostringstream out;
  out << OUTPUT;

  BOOST_CHECK_EQUAL(out.str(), CORRECT_OUTPUT);
}

BOOST_AUTO_TEST_CASE(testFirstKeyComparison)
{
  BOOST_CHECK(DATA < DATA1);
}

BOOST_AUTO_TEST_CASE(testSecondKeyComparison)
{
  BOOST_CHECK(DATA1 < DATA2);
}

BOOST_AUTO_TEST_CASE(testStringComparison)
{
  BOOST_CHECK(DATA2 < DATA3);
}

BOOST_AUTO_TEST_SUITE_END()
