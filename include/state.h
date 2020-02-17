#pragma once

#include "snake.h"
#include "pickup.h"
#include "bounds.h"
#include "countdown.h"

struct State
{
  Snake snake;
  Pickup pickup;
  Bounds bounds;

  int menuIndex = 0;
  bool isOnMainMenu = true;
  bool quit = false;

  Countdown countdown;

  int score = 0;

  State() : countdown(3.0f)
  {

  }

};