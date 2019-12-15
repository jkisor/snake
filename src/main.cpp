#include <iostream>

#include "game.h"
#include "window.h"
#include "show_message_console.h"

int main() {

  Window window;

  window.open();

  while (window.isOpen())
  {
    std::vector<std::string> events = window.events();

    // if(events.size() != 0 && events[0] == "QUIT")
    //   window.close();

    window.clear();
    window.display();
  }
  
  ShowMessageConsole showMessage;
  Game game(showMessage);
  game.run();

  return 0;
}