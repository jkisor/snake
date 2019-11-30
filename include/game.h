#pragma once

#include "showMessage.h"

class Game {
  
  ShowMessage * showMessage;

  public:

  Game(ShowMessage &showMessage);

  void run();

};
