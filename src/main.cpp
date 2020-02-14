#include <iostream>

#include "window.h"

#include <string>
#include <vector>
#include <algorithm>

#include "events.h"
#include "pressed_keys.h"
#include "action.h"

#include "bounds.h"

#include "snake.h"
#include "position.h"

#include "move.h"
#include "pickup.h"

#include "state.h"

#include "countdown_view.h"
#include "gameplay_controls.h"

#include "menu_controls.h"
#include "menu_option_view.h"
#include "menu_view.h"

#include "game_view.h"

int main() {
  State state;

  state.bounds = { 8, 8 };
  state.snake.positions = { {2,0}, {1,0}, {0,0} };
  state.snake.nextDirection = { 1, 0 };
  state.snake.currentDirection = { 1, 0 };
  state.pickup.position = { 5, 4 };

  Move move(state);

  // Time
  sf::Clock deltaClock;
  Countdown countdown(3.0f);
  float TICK_SECONDS = 0.5f;
  Countdown tickCountdown(TICK_SECONDS);
  Countdown fadeCountdown(2.0f);

  // Input
  PressedKeys pressedKeys;

  Controls * controls;

  GameplayControls gameplayControls(state);
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
    }

    window.clear();

    if(state.isOnMainMenu)
    {
      MenuView menuView(state);

      for(sf::Drawable * d : menuView.drawables())
        window.draw(*d);
    }
    else
    {
      GameView gameView(state);

      for(sf::Drawable * d : gameView.drawables())
        window.draw(*d);

    }

    window.display();
  }

  return 0;
}