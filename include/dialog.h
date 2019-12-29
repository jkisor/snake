#pragma once

#include <vector>
#include <string>

class Dialog
{
  public:

  std::vector<std::string> messages;
  int index = 0;

  Dialog();
  std::string message();
  bool isComplete();

};