#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <string>
#include <functional>
#include <iosfwd>
#include "bookmark.hpp"

using function = std::function<void(Bookmark &bookmarks, std::ostream &out)>;

function convertCommand(std::istream &in);
function add(std::istream &in);
function store(std::istream &in);
function insert(std::istream &in);
function deleteNote(std::istream &in);
function show(std::istream &in);
function move(std::istream &in);

void printInvalidCommand(Bookmark&, std::ostream& out);
void printInvalidStep(Bookmark&, std::ostream& out);

#endif
