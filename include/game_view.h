#pragma once

#include "bounds_view.h"
#include "snake_view.h"
#include "pickup_view.h"
#include "countdown_view.h"
#include "score_view.h"

#include "state.h"

class GameView
{
  public:
  State * state;

  BoundsView bounds_view;
  SnakeView snakeView;
  PickupView pickup_view;
  CountdownView countdownView;
  ScoreView scoreView;

  GameView(State &state);
  std::vector<sf::Drawable *> drawables();

};