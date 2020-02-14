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

#include "menu_controls.h"
#include "menu_option_view.h"
#include "menu_view.h"

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
  Countdown fadeCountdown(2.0f);

  // Input
  PressedKeys pressedKeys;

  Controls * controls;

  GameplayControls gameplayControls(dialog, presenter, state);
  MenuControls menuControls(state);

  controls = &gameplayControls;

  Window window;
  window.open();

  while (window.isOpen())
  {
    Events events = window.events();

    for(sf::Event e : events.keyPresses())
    {
      if ( !pressedKeys.contains(e.key.code)) {
        pressedKeys.add(e.key.code);
        controls->trigger(e.key.code);
      }
    }

    for(sf::Event e : events.keyReleases())
      pressedKeys.remove(e.key.code);

    float dt = deltaClock.restart().asSeconds();

    if(state.quit == true)
    {
      window.close();
      return 0;
    }

    if(state.isOnMainMenu)
    {
      controls = &menuControls;
    }
    else
    {
      controls = &gameplayControls;
      // if(!fadeCountdown.isDone())
      // {
      //   fadeCountdown = fadeCountdown.update(dt);
      // }
      // else
      // {
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
      // }
    }

    window.clear();

    if(state.isOnMainMenu)
    {
      MenuView menu_view(state);
      
      for(sf::Drawable * d : menu_view.drawables())
        window.draw(*d);
    }
    else
    {
      window.draw(BoundsView(state.bounds).shape);

      for(sf::Sprite sprite : snakeView.drawables(state.snake))
        window.draw(sprite);

      window.draw(PickupView(state.pickup).sprite);

      if(!countdown.isDone())
        window.draw(CountdownView(countdown).sprite);

      window.draw(dialogView.text);

      // sf::RectangleShape fadeShape;

      // fadeShape.setPosition(0, 0);
      // fadeShape.setSize(sf::Vector2f(800, 600));

      // if(!fadeCountdown.isDone())
      //   fadeShape.setFillColor(sf::Color(0,0,0, (fadeCountdown.secondsLeft / fadeCountdown.duration ) * 255) );
      // else
      //   fadeShape.setFillColor(sf::Color(0,0,0,0));

      // window.draw(fadeShape);
    }

    window.display();
  }

  return 0;
}