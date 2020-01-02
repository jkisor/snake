#pragma once

#include <string>

class PresenterInterface
{
  virtual void onChangeMessage(std::string message) = 0;
  virtual void onDone() = 0;
};
