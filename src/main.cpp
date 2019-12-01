#include <iostream>

#include "game.h"
#include "open_window_sfml.h"
#include "show_message_console.h"

int main() {
  OpenWindowSFML openWindow;
  ShowMessageConsole showMessage;

  Game game(openWindow, showMessage);
  game.run();

  return 0;
}