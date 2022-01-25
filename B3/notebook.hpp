#ifndef NOTEBOOK_HPP
#define NOTEBOOK_HPP

#include <list>
#include <string>
#include <iostream>

class Notebook
{
public:
  struct Note
  {
    std::string number;
    std::string name;
  };
  using iterator_type = std::list<Note>::iterator;

  Note& getCurrent(const iterator_type &current) const;
  void prev(const iterator_type &current) const;
  void next(const iterator_type &current) const;
  void insertBeforeCurrent(const iterator_type &current, const Note &note);
  void insertAfterCurrent(const iterator_type &current, const Note &note);
  void replaceCurrent(iterator_type &current, const Note &note);
  void insertBack(const Note &note);
  void shiftForward(iterator_type &current, int step) const;
  void shiftBack(iterator_type &current, int step) const;
  void deleteNote(iterator_type &current);

  size_t getSize() const;
  iterator_type begin();
  iterator_type end();

  friend std::ostream& operator<<(std::ostream &out, const Notebook::Note &note);
  friend std::istream& operator>>(std::istream& in, Notebook::Note& note);

private:
  std::list <Note> notes_;
};
#endif
