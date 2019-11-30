#pragma once

#include "show_message_interface.h"

class ShowMessageMock : public ShowMessageInterface {
  
  public:

  bool wasCalled = false;
  std::string argument;

  void show(std::string message) {
    wasCalled = true;
    argument = message;
  }

  bool wasCalledWith(std::string argument) {
    return ( wasCalled && this->argument == argument );
  }

};