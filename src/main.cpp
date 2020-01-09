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
#include "object.h"

#include "bounds.h"

#include "move_down.h"
#include "move_right.h"
#include "move_left.h"
#include "move_up.h"

PressedKeys pressedKeys;

std::unordered_map<sf::Keyboard::Key, Action*> actionByKey;

bool isKeyPresent(std::unordered_map<sf::Keyboard::Key, Action*> m, sf::Keyboard::Key key)
{
  return !(m.find(key) == m.end());
}

Object object;

int SIZE = 64;

int main() {
  Dialog dialog;

  DialogView dialogView;
  // dialogView.setString(dialog.message());

  Presenter presenter(dialogView);
  presenter.onChangeMessage(dialog.message());

  NextMessage nextMessage(dialog, presenter);
  actionByKey[sf::Keyboard::Z] = &nextMessage;

  MoveRight moveRight(object);
  actionByKey[sf::Keyboard::Right] = &moveRight;

  MoveLeft moveLeft(object);
  actionByKey[sf::Keyboard::Left] = &moveLeft;

  MoveUp moveUp(object);
  actionByKey[sf::Keyboard::Up] = &moveUp;

  MoveDown moveDown(object);
  actionByKey[sf::Keyboard::Down] = &moveDown;

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

    sf::RectangleShape bounds_rectangle;
    bounds_rectangle.setSize(sf::Vector2f(SIZE * BOUNDS_WIDTH, SIZE * BOUNDS_HEIGHT));
    bounds_rectangle.setOutlineColor(sf::Color::White);
    bounds_rectangle.setOutlineThickness(4);
    bounds_rectangle.setFillColor(sf::Color::Black);

    bounds_rectangle.setPosition(0, 0);

    window.draw(bounds_rectangle);

    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(SIZE, SIZE));
    rectangle.setPosition(object.x * SIZE, object.y * SIZE);

    window.draw(rectangle);

    window.draw(dialogView.text);

    window.display();
  }

  return 0;
}