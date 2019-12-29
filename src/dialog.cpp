#include "dialog.h"

Dialog::Dialog()
{
  messages = {
    "...",
    "Hello?",
    "...",
    "No way."
  };
}

std::string Dialog::message()
{
  return messages[index];
}

bool Dialog::isComplete()
{
  return index >= messages.size();
}