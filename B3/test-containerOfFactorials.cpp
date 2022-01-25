#include <string>
#include <sstream>
#include <boost/test/unit_test.hpp>
#include "container.hpp"
#include "iterator.hpp"

void containerOfFactorials(std::ostream &out);

BOOST_AUTO_TEST_SUITE(testIterator)

BOOST_AUTO_TEST_CASE(constructorNoThrowContainer)
{
  BOOST_CHECK_NO_THROW(ContainerForFactorial(4, 6));
}

BOOST_AUTO_TEST_CASE(testOperatorIncrement)
{
  ContainerForFactorial container(1, 6);
  ContainerForFactorial::IteratorForFactorial it = container.begin();

  BOOST_CHECK_EQUAL(*it, 1);
  BOOST_CHECK_EQUAL(*(++it), 2);
  BOOST_CHECK_EQUAL(*(it++), 2);
}

BOOST_AUTO_TEST_CASE(testOperatorDecrement)
{
  ContainerForFactorial container(5, 8);
  ContainerForFactorial::IteratorForFactorial it = container.end();

  BOOST_CHECK_EQUAL(*it, 40320);
  BOOST_CHECK_EQUAL(*(--it), 5040);
  BOOST_CHECK_EQUAL(*(it--), 5040);
}

BOOST_AUTO_TEST_CASE(testOperatorEquality)
{
  ContainerForFactorial container(2, 3);
  ContainerForFactorial::IteratorForFactorial it = container.begin();
  ContainerForFactorial::IteratorForFactorial it1 = container.begin();

  BOOST_CHECK_NO_THROW(it == it1);
  BOOST_CHECK(it == it1);
}

BOOST_AUTO_TEST_CASE(testOperatorInequality)
{
  ContainerForFactorial container(2, 3);
  ContainerForFactorial::IteratorForFactorial it = container.begin();
  ContainerForFactorial::IteratorForFactorial it1 = container.begin();
  it1++;

  BOOST_CHECK_NO_THROW(it != it1);
  BOOST_CHECK(it != it1);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(testContainerOfFactorial)

const std::string EXPECTED_FACTORIAL = "1 2 6 24 120 720 5040 40320 362880 3628800 \n"
                                       "3628800 362880 40320 5040 720 120 24 6 2 1 \n";
BOOST_AUTO_TEST_CASE(testCorrectTask)
{
  std::ostringstream out;
  BOOST_CHECK_NO_THROW(containerOfFactorials(out));
  BOOST_CHECK_EQUAL(out.str(), EXPECTED_FACTORIAL);
}

BOOST_AUTO_TEST_SUITE_END()
