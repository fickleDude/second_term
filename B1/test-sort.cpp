#include <stdexcept>
#include <vector>
#include <forward_list>
#include <sstream>
#include <string>
#include <boost/test/unit_test.hpp>
#include "sort_accessory.hpp"

void sort(const char *comparator, std::istream &in = std::cin, std::ostream &out = std::cout);

const char *ASC("ascending");
const char *DESC("descending");
const char *INVALID_ARGUMENT = "abc";

BOOST_AUTO_TEST_SUITE(testAccessorySort)

template<typename Container, typename Access>
bool isOrdered(Container &container, const char *direction)
{
  using indexType = typename Access::index;
  indexType left = Access::begin(container);
  indexType right = Access::end(container);
  indexType j = left;
  for (indexType i = left++; i != right; i++)
  {
    if (comparator(Access::getElement(container, j), Access::getElement(container, i), convertSortOption(direction)))
    {
      return 0;
    }
    j++;
  }
  return 1;
}

const std::vector<int> VECTOR{0, -5, 1, 1, 9, 10, 0, 1, 0, 5, -23, 65, 64, -11, 43, 39, 5};
const std::forward_list<int> LIST{9, 1, 31, -79, 65, 10, -1, 0, 15, 23, 63, 64, -18, 43, 59, 25};

BOOST_AUTO_TEST_CASE(testSelectionSortWithWrongCompareParameter)
{
  std::vector < int > vector(VECTOR);

  BOOST_CHECK_THROW((selectionSort<std::vector<int>,
  BracketsAccess<std::vector<int>>>(vector, convertSortOption(INVALID_ARGUMENT))), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testSelectionSortWithOperator)
{
  std::vector < int > vector(VECTOR);
  std::vector<int> vector1(VECTOR);

  BOOST_CHECK_NO_THROW((selectionSort<std::vector<int>, BracketsAccess<std::vector<int>>>(vector, ASCENDING)));
  BOOST_CHECK_NO_THROW((selectionSort<std::vector<int>, BracketsAccess<std::vector<int>>>(vector1, DESCENDING)));

  BOOST_CHECK((isOrdered<std::vector<int>, BracketsAccess<std::vector<int>>>(vector, ASC)) == 1);
  BOOST_CHECK((isOrdered<std::vector<int>, BracketsAccess<std::vector<int>>>(vector1, DESC)) == 1);
}

BOOST_AUTO_TEST_CASE(testSelectionSortWithAt)
{
  std::vector < int > vector(VECTOR);
  std::vector<int> vector1(VECTOR);

  BOOST_CHECK_NO_THROW((selectionSort<std::vector<int>, AtAccess<std::vector<int>>>(vector, ASCENDING)));
  BOOST_CHECK_NO_THROW((selectionSort<std::vector<int>, AtAccess<std::vector<int>>>(vector1, DESCENDING)));

  BOOST_CHECK((isOrdered<std::vector<int>, AtAccess<std::vector<int>>>(vector, ASC)) == 1);
  BOOST_CHECK((isOrdered<std::vector<int>, AtAccess<std::vector<int>>>(vector1, DESC)) == 1);
}

BOOST_AUTO_TEST_CASE(testSelectionSortWithIterator)
{
  std::forward_list < int > list(LIST);
  std::forward_list<int> list1(LIST);

  BOOST_CHECK_NO_THROW((selectionSort<std::forward_list<int>, IteratorAccess<std::forward_list<int>>>(list, ASCENDING)));
  BOOST_CHECK_NO_THROW((selectionSort<std::forward_list<int>, IteratorAccess<std::forward_list<int>>>(list1, DESCENDING)));

  BOOST_CHECK((isOrdered<std::forward_list<int>, IteratorAccess<std::forward_list<int>>>(list, ASC)) == 1);
  BOOST_CHECK((isOrdered<std::forward_list<int>, IteratorAccess<std::forward_list<int>>>(list1, DESC)) == 1);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(testSort)

std::string emptyInput("");
std::string incorrectInput("abc");
std::string correctInput("5 -12 -12 9 10 0 -9 -12 -1 23 65 64 11 43 39 -15");
std::string ascendingOutput("-15 -12 -12 -12 -9 -1 0 5 9 10 11 23 39 43 64 65 \n"
                            "-15 -12 -12 -12 -9 -1 0 5 9 10 11 23 39 43 64 65 \n-15 -12 -12 -12 -9 -1 0 5 9 10 11 23 39 43 64 65 \n");
std::string descendingOutput("65 64 43 39 23 11 10 9 5 0 -1 -9 -12 -12 -12 -15 \n"
                             "65 64 43 39 23 11 10 9 5 0 -1 -9 -12 -12 -12 -15 \n65 64 43 39 23 11 10 9 5 0 -1 -9 -12 -12 -12 -15 \n");

BOOST_AUTO_TEST_CASE(testSortWithEmptyContainer)
{
  std::istringstream in(emptyInput);
  std::ostringstream out;

  BOOST_CHECK_NO_THROW(sort(ASC, in, out));
}

BOOST_AUTO_TEST_CASE(testSortWithIncorrectInput)
{
  std::istringstream in(incorrectInput);
  std::ostringstream out;

  BOOST_CHECK_THROW(sort(ASC, in, out), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(testAscendingSort)
{
  std::istringstream in(correctInput);
  std::ostringstream out;

  BOOST_CHECK_NO_THROW(sort(ASC, in, out));

  BOOST_CHECK(out.str() == ascendingOutput);
}

BOOST_AUTO_TEST_CASE(testDescendingSort)
{
  std::istringstream in(correctInput);
  std::ostringstream out;

  BOOST_CHECK_NO_THROW(sort(DESC, in, out));

  BOOST_CHECK(out.str() == descendingOutput);
}

BOOST_AUTO_TEST_CASE(testSortWithWrongCompareParameter)
{
  std::istringstream in(correctInput);
  std::ostringstream out;

  BOOST_CHECK_THROW(sort(INVALID_ARGUMENT, in, out), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
