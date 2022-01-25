#include <stdexcept>
#include <vector>
#include <sstream>
#include <iostream>

#include <boost/test/unit_test.hpp>

void fillRandom(double* array, int size);
void vectorSort(const char* comparator, int size, std::ostream& out = std::cout);

const int SIZE = 20;

BOOST_AUTO_TEST_SUITE(testFillArray)

BOOST_AUTO_TEST_CASE(testRangeOfElements)
{
  std::vector < double > vector(SIZE);
  fillRandom(&vector[0], SIZE);

  for (int i = 0; i < SIZE; i++)
  {
    BOOST_CHECK((vector[i] >= -1.0) && (vector[i] <= 1.0));
  }
}

BOOST_AUTO_TEST_CASE(testInvalidSize)
{
  std::vector < double > vector(SIZE);

  BOOST_CHECK_THROW(fillRandom(&vector[0], -SIZE), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testInvalidArray)
{
  BOOST_CHECK_THROW(fillRandom(nullptr, SIZE), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(testFillArrayAndSort)

const char *ASC("ascending");
const char *DESC("descending");
const char *INVALID_ARGUMENT = "abc";

BOOST_AUTO_TEST_CASE(testInvalidSortDirection)
{
  BOOST_CHECK_THROW(vectorSort(INVALID_ARGUMENT, SIZE), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testInvalidSize)
{
  BOOST_CHECK_THROW(vectorSort(ASC, -SIZE), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testAscendingSort)
{
  std::ostringstream out;

  BOOST_CHECK_NO_THROW(vectorSort(ASC, SIZE, out));

  std::istringstream output;
  output.str(out.str());
  output.ignore(1000, '\n');
  double array[SIZE];
  output >> array[0];
  for (size_t i = 1; i < SIZE - 1; i++)
  {
    output >> array[i];
    BOOST_CHECK(array[i] >= array[i - 1]);
  }
}

BOOST_AUTO_TEST_CASE(testDescendingSort)
{
  std::ostringstream out;

  BOOST_CHECK_NO_THROW(vectorSort(DESC, SIZE, out));

  std::istringstream output;
  output.str(out.str());
  output.ignore(1000, '\n');
  double array[SIZE];
  output >> array[0];
  for (size_t i = 1; i < SIZE - 1; i++)
  {
    output >> array[i];
    BOOST_CHECK(array[i] <= array[i - 1]);
  }
}

BOOST_AUTO_TEST_SUITE_END()
