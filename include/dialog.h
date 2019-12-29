#pragma once

#include <vector>
#include <string>

class Dialog
{
  public:

  const std::vector<std::string> messages = {
    "...",
    "Hello?",
    "...",
    "No way."
  };
  int index = 0;

  std::string message();

  bool isComplete();

};