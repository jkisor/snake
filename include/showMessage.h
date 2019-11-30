#pragma once

#include <string>

class ShowMessage {
  public:
  virtual void show(std::string message) = 0;
};