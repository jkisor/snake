#include <iostream>

#include "game.h"
#include "window.h"
#include "show_message_console.h"

#include <string>

int main() {

  sf::Font font;
  font.loadFromFile("./basictitlefont.ttf");

  sf::Text text;

  // select the font
  text.setFont(font); // font is a sf::Font

  // set the string to display
  text.setString("Hello world");

  // set the character size
  text.setCharacterSize(24); // in pixels, not points!

  // set the color
  text.setFillColor(sf::Color::Black);

  // set the text style
  // text.setStyle(sf::Text::Bold | sf::Text::Underlined);
  //
  Window window;

  window.open();

  while (window.isOpen())
  {
    std::vector<std::string> events = window.events();

    // if(events.size() != 0 && events[0] == "QUIT")
    //   window.close();

    window.clear();

    window.draw(text);

    window.display();
  }

  ShowMessageConsole showMessage;
  Game game(showMessage);
  game.run();

  return 0;
}