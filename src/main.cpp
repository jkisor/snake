#include <iostream>

#include "game.h"
#include "window.h"
#include "show_message_console.h"

#include <string>
#include <vector>
#include <unordered_map>

#include "events.h"

#include <algorithm>

const std::vector<std::string> messages = {"One", "Two", "Three"};
int messageIndex = 0;
sf::Text text;

sf::Font loadFont(std::string file)
{
  sf::Font font;

  font.loadFromFile("./basictitlefont.ttf");

  return font;
};

#include "pressed_keys.h"

PressedKeys pressedKeys;

class Action
{
  public:
  virtual void call() {  };
};

class NextMessage : public Action
{
  public:

  void call() {
    messageIndex += 1;
    messageIndex %= messages.size();

    text.setString(messages[messageIndex]);
  }
};

std::unordered_map<sf::Keyboard::Key, Action*> actionByKey;


bool isKeyPresent(std::unordered_map<sf::Keyboard::Key, Action*> m, sf::Keyboard::Key key)
{
  return !(m.find(key) == m.end());
}

int main() {
  NextMessage nextMessage;
  actionByKey[sf::Keyboard::Key::Z] = &nextMessage;

  sf::Font font = loadFont("./basictitlefont.ttf");


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

    for(sf::Event e : events.keyPresses())
    {
      if ( !pressedKeys.contains(e.key.code)) {
        pressedKeys.add(e.key.code);

        if (isKeyPresent(actionByKey, e.key.code))
          actionByKey[e.key.code]->call();

      }
    }

    for(sf::Event e : events.keyReleases())
      pressedKeys.remove(e.key.code);

    window.clear();

    window.draw(text);

    window.display();
  }

  ShowMessageConsole showMessage;
  Game game(showMessage);
  game.run();

  return 0;
}