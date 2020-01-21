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

#include "pickup_view.h"
#include "bounds_view.h"

PressedKeys pressedKeys;

std::unordered_map<sf::Keyboard::Key, Action*> actionByKey;

bool isKeyPresent(std::unordered_map<sf::Keyboard::Key, Action*> m, sf::Keyboard::Key key)
{
  return !(m.find(key) == m.end());
}

int SIZE = 64;

#include "snake_view.h"
#include "state.h"

int main() {
  State state;

  state.bounds = { 8, 8 };

  state.snake.positions = { {2,0}, {1,0}, {0,0} };
  state.pickup.position = { 5, 4 };

  Dialog dialog;

  DialogView dialogView;

  SnakeView snakeView;

  Presenter presenter(dialogView);
  presenter.onChangeMessage(dialog.message());

  NextMessage nextMessage(dialog, presenter);
  actionByKey[sf::Keyboard::Z] = &nextMessage;

  MoveRight moveRight(state);
  actionByKey[sf::Keyboard::Right] = &moveRight;

  MoveLeft moveLeft(state);
  actionByKey[sf::Keyboard::Left] = &moveLeft;

  MoveUp moveUp(state);
  actionByKey[sf::Keyboard::Up] = &moveUp;

  MoveDown moveDown(state);
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

    window.draw(BoundsView(state.bounds).shape);
    window.draw(PickupView(state.pickup).shape);

    for(sf::RectangleShape shape : snakeView.drawables(state.snake))
      window.draw(shape);

    window.draw(dialogView.text);

    window.display();
  }

  return 0;
}