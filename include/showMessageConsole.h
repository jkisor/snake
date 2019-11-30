#pragma once

#include "showMessage.h"

class ShowMessageConsole : public ShowMessage {
  
  public:

  void show(std::string message) {
    std::cout << message << std::endl; 
  }

};
