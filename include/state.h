#pragma once

#include "snake.h"
#include "pickup.h"
#include "bounds.h"

struct State
{
  Snake snake;
  Pickup pickup;
  Bounds bounds;
};