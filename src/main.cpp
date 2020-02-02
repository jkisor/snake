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

#include "move.h"
#include "pickup.h"

#include "pickup_view.h"
#include "bounds_view.h"

#include "change_direction.h"

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
  state.snake.nextDirection = { 1, 0 };
  state.snake.currentDirection = { 1, 0 };

  state.pickup.position = { 5, 4 };

  Dialog dialog;

  DialogView dialogView;

  SnakeView snakeView;

  Presenter presenter(dialogView);
  presenter.onChangeMessage(dialog.message());

  NextMessage nextMessage(dialog, presenter);
  actionByKey[sf::Keyboard::Z] = &nextMessage;

  ChangeDirection changeDirectionRight(state, {1,0});
  actionByKey[sf::Keyboard::Right] = &changeDirectionRight;

  ChangeDirection changeDirectionLeft(state, {-1,0});
  actionByKey[sf::Keyboard::Left] = &changeDirectionLeft;

  ChangeDirection changeDirectionUp(state, {0,-1});
  actionByKey[sf::Keyboard::Up] = &changeDirectionUp;

  ChangeDirection changeDirectionDown(state, {0,1});
  actionByKey[sf::Keyboard::Down] = &changeDirectionDown;

  Move move(state);
  actionByKey[sf::Keyboard::Space] = &move;

  Window window;

  window.open();

  sf::Clock deltaClock;

  float accum = 0;

  float TICK_SECONDS = 0.50;

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

    float dt = deltaClock.restart().asSeconds();
    accum += dt;

    if(!state.snake.dead && accum >= TICK_SECONDS)
    {
      move.call();
      accum = 0;
    }

    window.clear();

    window.draw(BoundsView(state.bounds).shape);

    for(sf::Sprite sprite : snakeView.drawables(state.snake))
      window.draw(sprite);

    window.draw(PickupView(state.pickup).sprite);

    window.draw(dialogView.text);

    window.display();
  }

  return 0;
}