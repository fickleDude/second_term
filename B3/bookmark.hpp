#ifndef BOOKMARK_HPP
#define BOOKMARK_HPP

#include "notebook.hpp"
#include <string>
#include <map>
#include <ostream>

class Bookmark
{
public:
  Bookmark();

  void add(const Notebook::Note &note);
  void store(const std::string& markName, const std::string& newMarkName, std::ostream &out);
  void insertBefore(const std::string& markName, const Notebook::Note &note, std::ostream &out);
  void insertAfter(const std::string& markName, const Notebook::Note &note, std::ostream &out);
  void deleteNote(const std::string& markName, std::ostream& out);
  void show(const std::string& markName, std::ostream &out) const;
  void move(const std::string& markName, int step, std::ostream &out);
  void move(const std::string& markName, const std::string& step, std::ostream &out);

private:
  std::map <std::string, Notebook::iterator_type> bookmarks_;
  Notebook phoneBook_;
};
#endif
