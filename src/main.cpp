#include <iostream>

#include "game.h"
#include "show_message_console.h"

int main() {
  ShowMessageConsole showMessage;

  Game game(showMessage);
  game.run();

  return 0;
}