#include <iostream>

#include "window.h"

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

#include "events.h"
#include "pressed_keys.h"
#include "action.h"

#include "dialog.h"
#include "dialog_view.h"
#include "presenter.h"

#include "next_message.h"

PressedKeys pressedKeys;

std::unordered_map<sf::Keyboard::Key, Action*> actionByKey;

bool isKeyPresent(std::unordered_map<sf::Keyboard::Key, Action*> m, sf::Keyboard::Key key)
{
  return !(m.find(key) == m.end());
}

int main() {
  Dialog dialog;

  DialogView dialogView;
  // dialogView.setString(dialog.message());

  Presenter presenter(dialogView);
  presenter.onChangeMessage(dialog.message());
  
  NextMessage nextMessage(dialog, presenter);

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

    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(32, 32));
    rectangle.setOutlineColor(sf::Color::Blue);
    rectangle.setOutlineThickness(2);
    rectangle.setPosition(0, 0);
    
    window.draw(rectangle);

    sf::CircleShape shape(20);
    shape.setPosition(200, 0);
    shape.setFillColor(sf::Color(100, 250, 50));

    window.draw(shape);

    //
    window.draw(dialogView.text);

    window.display();
  }

  return 0;
}