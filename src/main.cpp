#include <iostream>

// #include "window.h"

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

#include "gameplay_controls.h"

#include "menu_controls.h"
#include "menu_option_view.h"
#include "menu_view.h"

#include "game_view.h"

int main() {
  State state;

  state.bounds = { 12, 8 };
  state.snake.positions = Positions({ {2,0}, {1,0}, {0,0} });
  state.snake.nextDirection = { 1, 0 };
  state.snake.currentDirection = { 1, 0 };
  state.pickup.position = { 5, 4 };

  Move move(state);

  // Time
  sf::Clock deltaClock;
  Countdown countdown(3.0f);
  float TICK_SECONDS = 0.5f;
  Countdown tickCountdown(TICK_SECONDS);

  // Input
  PressedKeys pressedKeys;

  Controls * controls;

  GameplayControls gameplayControls(state);
  MenuControls menuControls(state);

  controls = &gameplayControls;

  sf::RenderWindow window;

  window.create(sf::VideoMode(800, 600), "Snake by John Kisor");

  // High cpu usage unless limited
  // MUST be called after create.
  window.setFramerateLimit(60);

  while (window.isOpen())
  {
    Events events(window);

    for(sf::Event e : events.keyPresses())
    {
      if ( !pressedKeys.contains(e.key.code)) {
        pressedKeys.add(e.key.code);
        controls->trigger(e.key.code);
      }
    }

    for(sf::Event e : events.keyReleases())
      pressedKeys.remove(e.key.code);

    //

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

      if(!state.countdown.isDone())
        state.countdown = state.countdown.update(dt);
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

    window.clear(sf::Color::Black);

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