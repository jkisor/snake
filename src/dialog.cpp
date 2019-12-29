#include "dialog.h"

std::string Dialog::message()
{
  return messages[index];
}

bool Dialog::isComplete()
{
  return index >= messages.size();
}