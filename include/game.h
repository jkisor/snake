#pragma once

#include "show_message_interface.h"
#include "open_window_interface.h"


class Game {
  
  OpenWindowInterface * openWindow;
  ShowMessageInterface * showMessage;

  public:

  Game(OpenWindowInterface &openWindow, ShowMessageInterface &showMessage);

  void run();

};
