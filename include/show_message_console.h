#pragma once

#include "show_message_interface.h"

class ShowMessageConsole : public ShowMessageInterface {
  
  public:

  void show(std::string message) {
    std::cout << message << std::endl; 
  }

};
