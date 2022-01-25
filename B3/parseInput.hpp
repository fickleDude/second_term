#ifndef PARSE_INPUT_HPP
#define PARSE_INPUT_HPP

#include <string>
#include <istream>
#include "notebook.hpp"

std::string parseMarkName(std::istream& in);
std::string parseNumber(std::istream& in);
std::string parseName(std::istream& in);

std::istream& skipWhiteSpace(std::istream& in);

#endif
