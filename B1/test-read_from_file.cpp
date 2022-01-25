#include <stdexcept>

#include <boost/test/unit_test.hpp>

void readFromFile(const char* fileName);

BOOST_AUTO_TEST_SUITE(testReadFromFile)

BOOST_AUTO_TEST_CASE(testNullFileName)
{
  BOOST_CHECK_THROW(readFromFile(nullptr), std::runtime_error);
}

BOOST_AUTO_TEST_SUITE_END()
