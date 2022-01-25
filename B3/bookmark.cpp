#include "bookmark.hpp"
#include <cstdlib>
#include <cstring>

Bookmark::Bookmark()
{
  bookmarks_["current"] = phoneBook_.begin();
}

void Bookmark::add(const Notebook::Note &note)
{
  phoneBook_.insertBack(note);
  if (phoneBook_.getSize() == 1)
  {
    bookmarks_["current"] = phoneBook_.begin();
  }
}

void Bookmark::store(const std::string &markName, const std::string &newMarkName, std::ostream &out)
{
  std::map<std::string, Notebook::iterator_type>::iterator current = bookmarks_.find(markName);
  if (current != bookmarks_.end() && phoneBook_.getSize() != 0)
  {
    bookmarks_.emplace(newMarkName, current->second);
  }
  else
  {
    out << "<INVALID BOOKMARK>\n";
  }
}

void Bookmark::insertBefore(const std::string &markName, const Notebook::Note &note, std::ostream &out)
{
  std::map<std::string, Notebook::iterator_type>::iterator current = bookmarks_.find(markName);
  if (current != bookmarks_.end())
  {
    phoneBook_.insertBeforeCurrent(current->second, note);
    if (phoneBook_.getSize() == 1)
    {
      bookmarks_["current"] = phoneBook_.begin();
    }
  }
  else
  {
    out << "<INVALID BOOKMARK>\n";
  }
}

void Bookmark::insertAfter(const std::string &markName, const Notebook::Note &note, std::ostream &out)
{
  std::map<std::string, Notebook::iterator_type>::iterator current = bookmarks_.find(markName);
  if (current != bookmarks_.end())
  {
    phoneBook_.insertAfterCurrent(current->second, note);
    if (phoneBook_.getSize() == 1)
    {
      bookmarks_["current"] = phoneBook_.begin();
    }
  }
  else
  {
    out << "<INVALID BOOKMARK>\n";
  }
}

void Bookmark::deleteNote(const std::string &markName, std::ostream &out)
{
  auto current = bookmarks_.find(markName);
  if (current != bookmarks_.end())
  {
    Notebook::iterator_type dest = current->second;
    if (phoneBook_.getSize() == 1)
    {
      for (auto &replace : bookmarks_)
      {
        replace.second = phoneBook_.begin();
      }
    }
    else
    {
      for (auto &replace : bookmarks_)
      {
        if (dest == replace.second)
        {
          if (std::next(replace.second) != phoneBook_.end())
          {
            replace.second = std::next(dest);
          }
          else
          {
            replace.second = std::prev(dest);
          }
        }
      }
    }
    phoneBook_.deleteNote(dest);
  }
  else
  {
    out << "<INVALID BOOKMARK>\n";
  }
}

void Bookmark::show(const std::string &markName, std::ostream &out) const
{
  std::map<std::string, Notebook::iterator_type>::const_iterator current = bookmarks_.find(markName);
  if (current != bookmarks_.end())
  {
    if (phoneBook_.getSize() == 0)
    {
      out << "<EMPTY>\n";
      return;
    }
    out << *current->second << '\n';
  }
  else
  {
    out << "<INVALID BOOKMARK>\n";
  }
}

void Bookmark::move(const std::string &markName, int step, std::ostream &out)
{
  std::map<std::string, Notebook::iterator_type>::iterator current = bookmarks_.find(markName);
  if (current != bookmarks_.end())
  {
    if (step < 0)
    {
      phoneBook_.shiftBack(current->second, std::abs(step));
    }
    else
    {
      phoneBook_.shiftForward(current->second, step);
    }
  }
  else
  {
    out << "<INVALID BOOKMARK>\n";
  }
}

void Bookmark::move(const std::string &markName, const std::string &step, std::ostream &out)
{
  std::map<std::string, Notebook::iterator_type>::iterator current = bookmarks_.find(markName);
  if (current != bookmarks_.end())
  {
    static const std::string first = "first";
    static const std::string last = "last";
    if (step == first)
    {
      bookmarks_[current->first] = phoneBook_.begin();
    }
    else if (step == last)
    {
      bookmarks_[current->first] = std::prev(phoneBook_.end());
    }
    else
    {
      out << "<INVALID STEP>\n";
    }
  }
  else
  {
    out << "<INVALID BOOKMARK>\n";
  }
}
