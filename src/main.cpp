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

int BOUNDS_WIDTH = 8;
int BOUNDS_HEIGHT = 8;

#include "snake.h"
#include "position.h"

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

// Object object;
Snake snake;

int SIZE = 64;

int main() {
  Bounds bounds;
  bounds.width = 8;
  bounds.height = 8;

  Position p0;
  p0.x = 2;
  p0.y = 0;

  Position p1;
  p1.x = 1;
  p1.y = 0;

  Position p2;
  p2.x = 0;
  p2.y = 0;

  snake.positions.push_back(p0);
  snake.positions.push_back(p1);
  snake.positions.push_back(p2);

  // object.x = 2;
  // object.y = 0;
  // object.tailX = 1;
  // object.tailY = 0;
  // object.otherTailX = 0;
  // object.otherTailY = 0;

  Dialog dialog;

  DialogView dialogView;
  // dialogView.setString(dialog.message());

  Presenter presenter(dialogView);
  presenter.onChangeMessage(dialog.message());

  NextMessage nextMessage(dialog, presenter);
  actionByKey[sf::Keyboard::Z] = &nextMessage;

  MoveRight moveRight(snake, bounds);
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
    bounds_rectangle.setSize(sf::Vector2f(SIZE * BOUNDS_WIDTH, SIZE * BOUNDS_HEIGHT));
    bounds_rectangle.setOutlineColor(sf::Color::White);
    bounds_rectangle.setOutlineThickness(4);
    bounds_rectangle.setFillColor(sf::Color::Black);

    bounds_rectangle.setPosition(0, 0);

    window.draw(bounds_rectangle);

    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(SIZE, SIZE));
    // rectangle.setPosition(object.x * SIZE, object.y * SIZE);
    rectangle.setPosition(snake.positions[0].x * SIZE, snake.positions[0].y * SIZE);
    rectangle.setFillColor(sf::Color::Green);

    window.draw(rectangle);

    sf::RectangleShape tailRectangle;
    tailRectangle.setSize(sf::Vector2f(SIZE, SIZE));
    // tailRectangle.setPosition(object.tailX * SIZE, object.tailY * SIZE);
    tailRectangle.setPosition(snake.positions[1].x * SIZE, snake.positions[1].y * SIZE);

    tailRectangle.setFillColor(sf::Color::Red);

    window.draw(tailRectangle);

    sf::RectangleShape otherTailRectangle;
    otherTailRectangle.setSize(sf::Vector2f(SIZE, SIZE));
    // otherTailRectangle.setPosition(object.otherTailX * SIZE, object.otherTailY * SIZE);
    otherTailRectangle.setPosition(snake.positions[2].x * SIZE, snake.positions[2].y * SIZE);

    otherTailRectangle.setFillColor(sf::Color::Red);

    window.draw(otherTailRectangle);

    window.draw(dialogView.text);

    window.display();
  }

  return 0;
}