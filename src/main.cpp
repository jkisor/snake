#include <iostream>

#include "game.h"
#include "showMessageConsole.h"

int main() {
  ShowMessageConsole showMessage;

  Game game(showMessage);
  game.run();

  return 0;
}