#pragma once

#include <vector>
#include <string>

class Dialog
{
  public:

  const std::vector<std::string> messages = {"One", "Two", "Three"};
  int index = 0;

  std::string message();

  bool isComplete();

};