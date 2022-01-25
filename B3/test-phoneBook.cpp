#include <string>
#include <sstream>
#include <boost/test/unit_test.hpp>
#include "interface.hpp"

void phoneBook(std::istream &in, std::ostream &out);

BOOST_AUTO_TEST_SUITE(testOfPhoneBook)

const std::string ADD = "add 79781234567 \"Adam Kozlevich\"\n";
const std::string INVALID_ADD = "add \"Alexander\"Koreiko\"\n";
const std::string ADD1 = "add 79539876543 \"\\\"Kisa\\\"Vorobyaninov\"\n";
const std::string ADD2 = "add 78652664347 \"Shura Balaganov\"\n";
const std::string STORE = "store current first\n";
const std::string SHOW = "show current\n";
const std::string INSERT_BEFORE = "insert before current 79234567890 \"Ella Shchukina\"\n";
const std::string INSERT_AFTER = "insert after current 75425674312 \"Zosia Sinitskaya\"\n";
const std::string INVALID_BOOKMARK = "insert after first 75425674312 \"Zosia Sinitskaya\"\n";
const std::string INVALID_CONTACT = "add 75425674312 \"Zosi\"a\"Si\"nitskaya\"\n";
const std::string INVALID_CONTACT1 = "add 7j4f5674d12 \"Zosia Sinitskaya\"\n";
const std::string DELETE = "delete current\n";
const std::string MOVE_PLUS1 = "move current 1\n";
const std::string MOVE_PLUS2 = "move current +2\n";
const std::string MOVE_MINUS1 = "move current -1\n";
const std::string MOVE_TO_LAST = "move current last\n";
const std::string MOVE_TO_FIRST = "move current first\n";
const std::string OUTPUT = "79781234567 Adam Kozlevich\n";
const std::string OUTPUT1 = "79539876543 \"Kisa\"Vorobyaninov\n";
const std::string OUTPUT2 = "78652664347 Shura Balaganov\n";
const std::string OUTPUT_INSERT_BEFORE = "79234567890 Ella Shchukina\n";
const std::string OUTPUT_INSERT_AFTER = "75425674312 Zosia Sinitskaya\n";
const std::string EMPTY = "<EMPTY>\n";
const std::string INVALID_BOOKMARK_OUTPUT = "<INVALID BOOKMARK>\n";
const std::string INVALID_COMMAND = "<INVALID COMMAND>\n";
const std::string INVALID_STEP_OUTPUT = "<INVALID STEP>\n";
const std::string INVALID_COMMAND_INPUT = "insert befor\n";
const std::string INVALID_STEP = "move current 5r\n";
const std::string INVALID_STEP1 = "move current 6\n";
const std::string INVALID_STEP2 = "move current -6\n";

BOOST_AUTO_TEST_CASE(testCorrectAdd)
{
  std::istringstream input(ADD);
  std::ostringstream output;

  BOOST_CHECK_NO_THROW(phoneBook(input, output));
}

BOOST_AUTO_TEST_CASE(testInvalidAdd)
{
  std::istringstream input(INVALID_ADD);
  std::ostringstream output;

  BOOST_CHECK_NO_THROW(phoneBook(input, output));
  BOOST_CHECK_EQUAL(output.str(), INVALID_COMMAND);
}

BOOST_AUTO_TEST_CASE(testCorrectStore)
{
  std::istringstream input(ADD + STORE);
  std::ostringstream output;

  BOOST_CHECK_NO_THROW(phoneBook(input, output));
}

BOOST_AUTO_TEST_CASE(testCorrectInsertBefore)
{
  std::istringstream input(ADD + INSERT_BEFORE + MOVE_MINUS1 + SHOW);
  std::ostringstream output;

  BOOST_CHECK_NO_THROW(phoneBook(input, output));
  BOOST_CHECK_EQUAL(output.str(), OUTPUT_INSERT_BEFORE);
}

BOOST_AUTO_TEST_CASE(testEmptyInsertBefore)
{
  std::istringstream input(INSERT_BEFORE);
  std::ostringstream output;

  BOOST_CHECK_NO_THROW(phoneBook(input, output));
}

BOOST_AUTO_TEST_CASE(testCorrectInsertAfter)
{
  std::istringstream input(ADD + INSERT_AFTER + MOVE_PLUS1 + SHOW);
  std::ostringstream output;

  BOOST_CHECK_NO_THROW(phoneBook(input, output));
  BOOST_CHECK_EQUAL(output.str(), OUTPUT_INSERT_AFTER);
}

BOOST_AUTO_TEST_CASE(testCorrectShow)
{
  std::istringstream input(ADD + SHOW);
  std::ostringstream output;

  BOOST_CHECK_NO_THROW(phoneBook(input, output));
  BOOST_CHECK_EQUAL(output.str(), OUTPUT);
}

BOOST_AUTO_TEST_CASE(testShowWithQuotes)
{
  std::istringstream input(ADD1 + SHOW);
  std::ostringstream output;

  BOOST_CHECK_NO_THROW(phoneBook(input, output));
  BOOST_CHECK_EQUAL(output.str(), OUTPUT1);
}

BOOST_AUTO_TEST_CASE(testEmptyShow)
{
  std::istringstream input(SHOW);
  std::ostringstream output;

  BOOST_CHECK_NO_THROW(phoneBook(input, output));
  BOOST_CHECK_EQUAL(output.str(), EMPTY);
}

BOOST_AUTO_TEST_CASE(testCorrectDelete)
{
  std::istringstream input(ADD + ADD1 + DELETE + SHOW);
  std::istringstream input1(ADD + ADD1 + INSERT_AFTER + MOVE_PLUS2 + DELETE + SHOW);
  std::istringstream input2(ADD + DELETE + SHOW);
  std::ostringstream output;
  std::ostringstream output1;
  std::ostringstream output2;

  BOOST_CHECK_NO_THROW(phoneBook(input, output));
  BOOST_CHECK_EQUAL(output.str(), OUTPUT1);
  BOOST_CHECK_NO_THROW(phoneBook(input1, output1));
  BOOST_CHECK_EQUAL(output1.str(), OUTPUT_INSERT_AFTER);
  BOOST_CHECK_NO_THROW(phoneBook(input2, output2));
  BOOST_CHECK_EQUAL(output2.str(), EMPTY);
}

BOOST_AUTO_TEST_CASE(testCorrectMoveToLast)
{
  std::istringstream input(ADD + ADD1 + ADD2 + MOVE_TO_LAST + SHOW);
  std::ostringstream output;

  BOOST_CHECK_NO_THROW(phoneBook(input, output));
  BOOST_CHECK_EQUAL(output.str(), OUTPUT2);
}

BOOST_AUTO_TEST_CASE(testCorrectMoveForward)
{
  std::istringstream input(ADD + ADD1 + ADD2 + MOVE_PLUS2 + SHOW);
  std::ostringstream output;

  BOOST_CHECK_NO_THROW(phoneBook(input, output));
  BOOST_CHECK_EQUAL(output.str(), OUTPUT2);
}

BOOST_AUTO_TEST_CASE(testCorrectMoveBack)
{
  std::istringstream input(ADD + ADD1 + ADD2 + MOVE_PLUS2 + MOVE_MINUS1 + SHOW);
  std::ostringstream output;

  BOOST_CHECK_NO_THROW(phoneBook(input, output));
  BOOST_CHECK_EQUAL(output.str(), OUTPUT1);
}

BOOST_AUTO_TEST_CASE(testInvalidMoveStep)
{
  std::istringstream input(ADD + INVALID_STEP);
  std::ostringstream output;
  std::istringstream input1(ADD + INVALID_STEP1);
  std::ostringstream output1;
  std::istringstream input2(ADD + INVALID_STEP2);
  std::ostringstream output2;

  BOOST_CHECK_NO_THROW(phoneBook(input, output));
  BOOST_CHECK_EQUAL(output.str(), INVALID_STEP_OUTPUT);
  BOOST_CHECK_NO_THROW(phoneBook(input1, output1));
  BOOST_CHECK_NO_THROW(phoneBook(input2, output2));
}

BOOST_AUTO_TEST_CASE(testCorrectMoveToFirst)
{
  std::istringstream input(ADD + ADD1 + ADD2 + MOVE_PLUS2 + MOVE_TO_FIRST + SHOW);
  std::ostringstream output;

  BOOST_CHECK_NO_THROW(phoneBook(input, output));
  BOOST_CHECK_EQUAL(output.str(), OUTPUT);
}

BOOST_AUTO_TEST_CASE(testInvalidCommand)
{
  std::istringstream input(INVALID_COMMAND_INPUT);
  std::ostringstream output;

  BOOST_CHECK_NO_THROW(phoneBook(input, output));
  BOOST_CHECK_EQUAL(output.str(), INVALID_COMMAND);
}

BOOST_AUTO_TEST_CASE(testInvalidContact)
{
  std::istringstream input(INVALID_CONTACT);
  std::istringstream input1(INVALID_CONTACT1);
  std::ostringstream output;
  std::ostringstream output1;

  BOOST_CHECK_NO_THROW(phoneBook(input, output));
  BOOST_CHECK_EQUAL(output.str(), INVALID_COMMAND);
  BOOST_CHECK_NO_THROW(phoneBook(input1, output1));
  BOOST_CHECK_EQUAL(output1.str(), INVALID_COMMAND);
}

BOOST_AUTO_TEST_CASE(testInvalidBookMark)
{
  std::istringstream input(ADD + INVALID_BOOKMARK);
  std::ostringstream output;

  BOOST_CHECK_NO_THROW(phoneBook(input, output));
  BOOST_CHECK_EQUAL(output.str(), INVALID_BOOKMARK_OUTPUT);
}
BOOST_AUTO_TEST_SUITE_END()
