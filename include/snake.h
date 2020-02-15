#pragma once

#include "positions.h"
#include "position.h"
#include "direction.h"

struct Snake
{
  Positions positions;
  bool dead = false;

  Direction currentDirection;
  Direction nextDirection;

  Position& head();
  Position tail();

  bool isCollidingWithSelf();
  Snake grow(Position position);
  Snake kill();
  Snake move();

};