#include <iostream>

#include "game.h"
#include "window.h"
#include "show_message_console.h"

#include <string>
#include <vector>

#include "events.h"

const std::vector<std::string> messages = {"1", "2", "3"};
int messageIndex = 0;

sf::Font loadFont(std::string file)
{
  sf::Font font;

  font.loadFromFile("./basictitlefont.ttf");

  return font;
};

int main() {

  sf::Font font = loadFont("./basictitlefont.ttf");

  sf::Text text;

  // select the font
  text.setFont(font); // font is a sf::Font

  // set the string to display
  text.setString(messages[messageIndex]);

  // set the character size
  text.setCharacterSize(48); // in pixels, not points!

  // set the color
  text.setFillColor(sf::Color::Black);

  // set the text style
  // text.setStyle(sf::Text::Bold | sf::Text::Underlined);
  text.setStyle(sf::Text::Bold);

  text.setPosition(400, 0);
  //
  Window window;

  window.open();

  while (window.isOpen())
  {
    Events events = window.events();

    if(events.keyPresses().size() > 0)
    {
      messageIndex += 1;
      messageIndex %= messages.size();

      text.setString(messages[messageIndex]);
    }

    window.clear();

    window.draw(text);

    window.display();
  }

  ShowMessageConsole showMessage;
  Game game(showMessage);
  game.run();

  return 0;
}