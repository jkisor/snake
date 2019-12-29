#include <iostream>

#include "game.h"
#include "window.h"
#include "show_message_console.h"

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

#include "events.h"
#include "pressed_keys.h"
#include "action.h"

const std::vector<std::string> messages = {"One", "Two", "Three"};
int messageIndex = 0;
PressedKeys pressedKeys;

class DialogView
{

  public:
  
  sf::Font font;
  sf::Text text;

  DialogView()
  {
    font.loadFromFile("./basictitlefont.ttf");
    text.setFont(font);
    text.setString("");
    text.setCharacterSize(48); // in pixels, not points!
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    text.setPosition(400, 0);
  }

  void setString(std::string string)
  {
    text.setString(string);
  }

  void clear()
  {
    text.setString("");
  }
};

class Presenter
{
  DialogView * view;

  public:

  Presenter(DialogView &v)
  {
    view = &v;
  }

  void onChangeMessage(std::string message)
  {
    view->setString(message);
  }

  void onDone()
  {
    view->clear();
  }
};

class NextMessage : public Action
{
  Presenter * presenter;

  public:

  NextMessage(Presenter &p)
  {
    presenter = &p;
  }

  void call()
  {
    messageIndex += 1;

    if (messageIndex < messages.size())
      presenter->onChangeMessage(messages[messageIndex]);
    else
      presenter->onDone();
  }
};

std::unordered_map<sf::Keyboard::Key, Action*> actionByKey;


bool isKeyPresent(std::unordered_map<sf::Keyboard::Key, Action*> m, sf::Keyboard::Key key)
{
  return !(m.find(key) == m.end());
}

int main() {

  DialogView dialogView;
  dialogView.setString(messages[messageIndex]);

  Presenter presenter(dialogView);
  NextMessage nextMessage(presenter);

  actionByKey[sf::Keyboard::Key::Z] = &nextMessage;

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

    window.draw(dialogView.text);

    window.display();
  }

  ShowMessageConsole showMessage;
  Game game(showMessage);
  game.run();

  return 0;
}