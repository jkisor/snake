#include <iostream>

#include "window.h"

#include <string>
#include <vector>
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

#include "controls.h"

#include "snake_view.h"
#include "state.h"

#include "countdown_view.h"

int main() {

  PressedKeys pressedKeys;
  Controls controls;

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
  controls.set(sf::Keyboard::Z, nextMessage);

  ChangeDirection changeDirectionRight(state, {1,0});
  controls.set(sf::Keyboard::Right, changeDirectionRight);

  ChangeDirection changeDirectionLeft(state, {-1,0});
  controls.set(sf::Keyboard::Left, changeDirectionLeft);

  ChangeDirection changeDirectionUp(state, {0,-1});
  controls.set(sf::Keyboard::Up, changeDirectionUp);

  ChangeDirection changeDirectionDown(state, {0,1});
  controls.set(sf::Keyboard::Down, changeDirectionDown);

  Move move(state);

  Window window;

  window.open();

  sf::Clock deltaClock;

  float accum = 0.0f;

  Countdown countdown(3.0f);

  float TICK_SECONDS = 0.5f;

  while (window.isOpen())
  {
    Events events = window.events();

    for(sf::Event e : events.keyPresses())
    {
      if ( !pressedKeys.contains(e.key.code)) {
        pressedKeys.add(e.key.code);
        controls.trigger(e.key.code);
      }
    }

    for(sf::Event e : events.keyReleases())
      pressedKeys.remove(e.key.code);

    float dt = deltaClock.restart().asSeconds();

    if(!countdown.isDone())
      countdown = countdown.update(dt);
    else
    {
      accum += dt;

      if(!state.snake.dead && accum >= TICK_SECONDS)
      {
        move.call();
        accum = 0;
      }

    }

    window.clear();

    window.draw(BoundsView(state.bounds).shape);

    for(sf::Sprite sprite : snakeView.drawables(state.snake))
      window.draw(sprite);

    window.draw(PickupView(state.pickup).sprite);

    if(!countdown.isDone())
      window.draw(CountdownView(countdown).sprite);

    window.draw(dialogView.text);

    window.display();
  }

  return 0;
}