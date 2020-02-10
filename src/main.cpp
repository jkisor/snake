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

#include "bounds.h"

#include "snake.h"
#include "position.h"

#include "move.h"
#include "pickup.h"

#include "pickup_view.h"
#include "bounds_view.h"

#include "snake_view.h"
#include "state.h"

#include "countdown_view.h"
#include "gameplay_controls.h"

int main() {
  State state;

  state.bounds = { 8, 8 };
  state.snake.positions = { {2,0}, {1,0}, {0,0} };
  state.snake.nextDirection = { 1, 0 };
  state.snake.currentDirection = { 1, 0 };
  state.pickup.position = { 5, 4 };

  // Dialog demo
  Dialog dialog;
  DialogView dialogView;
  Presenter presenter(dialogView);
  presenter.onChangeMessage(dialog.message());

  Move move(state);
  SnakeView snakeView;

  // Time
  sf::Clock deltaClock;
  Countdown countdown(3.0f);
  float TICK_SECONDS = 0.5f;
  Countdown tickCountdown(TICK_SECONDS);

  // Input
  PressedKeys pressedKeys;
  GameplayControls controls(dialog, presenter, state);

  Window window;
  window.open();

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
      tickCountdown = tickCountdown.update(dt);

      if(!state.snake.dead && tickCountdown.isDone())
      {
        move.call();
        tickCountdown = Countdown(TICK_SECONDS);
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