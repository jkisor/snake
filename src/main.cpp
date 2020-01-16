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

#include "bounds.h"

#include "snake.h"
#include "position.h"

#include "move_down.h"
#include "move_right.h"
#include "move_left.h"
#include "move_up.h"
#include "pickup.h"

PressedKeys pressedKeys;

std::unordered_map<sf::Keyboard::Key, Action*> actionByKey;

bool isKeyPresent(std::unordered_map<sf::Keyboard::Key, Action*> m, sf::Keyboard::Key key)
{
  return !(m.find(key) == m.end());
}

int SIZE = 64;

#include "snake_view.h"

int main() {
  Snake snake;
  Pickup pickup;

  Bounds bounds;
  bounds.width = 8;
  bounds.height = 8;

  snake.positions.push_back({2,0});
  snake.positions.push_back({1,0});
  snake.positions.push_back({0,0});

  pickup.position.x = 5;
  pickup.position.y = 0;

  Dialog dialog;

  DialogView dialogView;

  SnakeView snakeView;

  Presenter presenter(dialogView);
  presenter.onChangeMessage(dialog.message());

  NextMessage nextMessage(dialog, presenter);
  actionByKey[sf::Keyboard::Z] = &nextMessage;

  MoveRight moveRight(snake, bounds, pickup);
  actionByKey[sf::Keyboard::Right] = &moveRight;

  MoveLeft moveLeft(snake);
  actionByKey[sf::Keyboard::Left] = &moveLeft;

  MoveUp moveUp(snake);
  actionByKey[sf::Keyboard::Up] = &moveUp;

  MoveDown moveDown(snake, bounds);
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
    bounds_rectangle.setSize(sf::Vector2f(SIZE * bounds.width, SIZE * bounds.height));
    bounds_rectangle.setOutlineColor(sf::Color::White);
    bounds_rectangle.setOutlineThickness(4);
    bounds_rectangle.setFillColor(sf::Color::Black);
    bounds_rectangle.setPosition(0, 0);

    window.draw(bounds_rectangle);

    sf::RectangleShape pickupRect;
    pickupRect.setSize(sf::Vector2f(SIZE, SIZE));
    pickupRect.setFillColor(sf::Color::Yellow);
    pickupRect.setPosition(pickup.position.x * SIZE, pickup.position.y * SIZE);

    window.draw(pickupRect);

    for(sf::RectangleShape shape : snakeView.drawables(snake))
      window.draw(shape);

    window.draw(dialogView.text);

    window.display();
  }

  return 0;
}