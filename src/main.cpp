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

int x = 0;
int y = 0;

int SIZE = 64;

int BOUNDS_WIDTH = 4;
int BOUNDS_HEIGHT = 4;

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

        if( e.key.code == sf::Keyboard::Right)
        {
          if( x < BOUNDS_WIDTH-1)
            x += 1;
        }
        else if( e.key.code == sf::Keyboard::Left)
        {
          if( x > 0 )
            x -= 1;
        }
        else if( e.key.code == sf::Keyboard::Up)
        {
          if( y > 0 )
          y -= 1;
        }
        else if ( e.key.code == sf::Keyboard::Down)
        {
          if( y < BOUNDS_HEIGHT-1)
            y += 1;
        }

      }
    }

    for(sf::Event e : events.keyReleases())
      pressedKeys.remove(e.key.code);

    window.clear();

    sf::RectangleShape bounds_rectangle;
    bounds_rectangle.setSize(sf::Vector2f(SIZE * BOUNDS_WIDTH, SIZE * BOUNDS_HEIGHT));
    bounds_rectangle.setOutlineColor(sf::Color::White);
    bounds_rectangle.setFillColor(sf::Color::Black);

    bounds_rectangle.setOutlineThickness(2);
    bounds_rectangle.setPosition(0, 0);

    window.draw(bounds_rectangle);

    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(SIZE, SIZE));
    rectangle.setPosition(x * SIZE, y * SIZE);

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