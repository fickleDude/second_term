#include "notebook.hpp"
#include <stdexcept>

std::string parseName(std::istream& in);
std::string parseNumber(std::istream& in);

Notebook::iterator_type Notebook::begin()
{
  return notes_.begin();
}

Notebook::iterator_type Notebook::end()
{
  return notes_.end();
}

Notebook::Note &Notebook::getCurrent(const iterator_type &current) const
{
  if (notes_.empty())
  {
    throw std::runtime_error("Notebook is empty!");
  }
  return *current;
}

void Notebook::prev(const iterator_type &current) const
{
  if (notes_.empty())
  {
    throw std::runtime_error("Notebook is empty!");
  }
  if (current == notes_.begin())
  {
    throw std::runtime_error("It is the first note!");
  }
  std::prev(current);
}

void Notebook::next(const iterator_type &current) const
{
  if (notes_.empty())
  {
    throw std::runtime_error("Notebook is empty!");
  }
  if (std::next(current) == notes_.end())
  {
    throw std::runtime_error("It is the last note!");
  }
  std::next(current);
}

void Notebook::insertBeforeCurrent(const iterator_type &current, const Note &note)
{
  if (notes_.empty())
  {
    notes_.push_front(note);
    return;
  }
  notes_.insert(current, note);
}

void Notebook::insertAfterCurrent(const iterator_type &current, const Note &note)
{
  if (notes_.empty())
  {
    notes_.push_front(note);
    return;
  }
  notes_.insert(std::next(current), note);
}

void Notebook::replaceCurrent(iterator_type &current, const Note &note)
{
  *current = note;
}

void Notebook::insertBack(const Note &note)
{
  notes_.push_back(note);
}

void Notebook::shiftForward(iterator_type &current, int step) const
{
  iterator_type tmp = current;
  size_t counter = step;
  while ((counter > 0) && (tmp != std::prev(notes_.end())))
  {
    tmp = std::next(tmp);
    --counter;
  }
  if (counter == 0)
  {
    current = tmp;
  }
  else
  {
    return;
  }
}

void Notebook::shiftBack(iterator_type &current, int step) const
{
  iterator_type tmp = current;
  size_t counter = step;
  while ((counter > 0) && (tmp != notes_.begin()))
  {
    tmp = std::prev(tmp);
    --counter;
  }
  if (counter == 0)
  {
    current = tmp;
  }
  else
  {
    return;
  }
}

size_t Notebook::getSize() const
{
  return notes_.size();
}

void Notebook::deleteNote(iterator_type &current)
{
  notes_.erase(current);
}

std::ostream &operator<<(std::ostream &out, const Notebook::Note &note)
{
  out << note.number << " " << note.name;
  return out;
}

std::istream& operator>>(std::istream& in, Notebook::Note& note)
{
  note.number = parseNumber(in);
  note.name = parseName(in);
  return in;
}
