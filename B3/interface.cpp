#include "interface.hpp"
#include <iostream>
#include <map>
#include <string>
#include "skipWhiteSpace.hpp"

std::string parseName(std::istream &in);
std::string parseNumber(std::istream &in);
std::string parseMarkName(std::istream &in);

void printInvalidCommand(Bookmark&, std::ostream& out)
{
  out << "<INVALID COMMAND>\n";
}

void printInvalidStep(Bookmark&, std::ostream& out)
{
  out << "<INVALID STEP>\n";;
}

function convertCommand(std::istream &in)
{
  std::map < std::string, function(*)(std::istream & ) > table =
  {
      {"add",    add},
      {"store",  store},
      {"insert", insert},
      {"delete", deleteNote},
      {"show",   show},
      {"move",   move}
  };
  std::string command;
  in >> skipWhiteSpace >> command;
  auto currentCommand = table.find(command);
  if (currentCommand != table.end())
  {
    return currentCommand->second(in);
  }
  return printInvalidCommand;

}

function add(std::istream &in)
{
  Notebook::Note note{};
  in >> note;
  if (note.number.empty() || note.name.empty())
  {
    return printInvalidCommand;
  }
  return [note](Bookmark &phoneBook, std::ostream &)
  {
    phoneBook.add(note);
  };
}

function store(std::istream &in)
{
  std::string markName = parseMarkName(in);
  std::string newMarkName = parseMarkName(in);
  if (markName.empty() || newMarkName.empty())
  {
    return printInvalidCommand;
  }
  return [markName, newMarkName](Bookmark &phoneBook, std::ostream &out)
  {
    phoneBook.store(markName, newMarkName, out);
  };
}

function insert(std::istream &in)
{
  std::string direction;
  in >> skipWhiteSpace >> direction;
  std::string markName = parseMarkName(in);
  Notebook::Note note{};
  in >> note;
  if (markName.empty() || note.number.empty() || note.name.empty())
  {
    return printInvalidCommand;
  }
  if (direction == "before")
  {
    return [markName, note](Bookmark &phoneBook, std::ostream &out)
    {
      phoneBook.insertBefore(markName, note, out);
    };
  }
  else if (direction == "after")
  {
    return [markName, note](Bookmark &phoneBook, std::ostream &out)
    {
      phoneBook.insertAfter(markName, note, out);
    };
  }
  else
  {
    return printInvalidCommand;
  }
}

function deleteNote(std::istream &in)
{
  std::string markName = parseMarkName(in);
  if (markName.empty())
  {
    return printInvalidCommand;
  }
  return [markName](Bookmark &phoneBook, std::ostream &out)
  {
    phoneBook.deleteNote(markName, out);
  };
}

function show(std::istream &in)
{
  std::string markName = parseMarkName(in);
  if (markName.empty())
  {
    return printInvalidCommand;
  }
  return [markName](Bookmark &phoneBook, std::ostream &out)
  {
    phoneBook.show(markName, out);
  };
}

function move(std::istream &in)
{
  std::string markName = parseMarkName(in);
  std::string step;
  getline(in >> skipWhiteSpace, step);
  if (markName.empty() || step.empty())
  {
    return printInvalidCommand;
  }
  if (step == "first")
  {
    return [markName, step](Bookmark &phoneBook, std::ostream &out)
    {
      phoneBook.move(markName, step, out);
    };
  }
  else if (step == "last")
  {
    return [markName, step](Bookmark &phoneBook, std::ostream &out)
    {
      phoneBook.move(markName, step, out);
    };
  }
  else
  {
    if (step[0] != '+' && step[0] != '-' && !isdigit(step[0]))
    {
        return printInvalidStep;
    }
    for (size_t i = 1; i < step.size(); i++)
    {
      if (!isdigit(step[i]))
      {
        return printInvalidStep;
      }
    }
    return [markName, step](Bookmark &phoneBook, std::ostream &out)
    {
      phoneBook.move(markName, std::stoi(step), out);
    };
  }
}
