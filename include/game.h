#pragma once

#include "show_message_interface.h"

class Game {
  
  ShowMessageInterface * showMessage;

  public:

  Game(ShowMessageInterface &showMessage);

  void run();

};
