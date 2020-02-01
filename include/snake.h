#pragma once

#include <vector>
#include "position.h"
#include "direction.h"

struct Snake
{
  std::vector<Position> positions;
  bool dead = false;

  Direction currentDirection;
  Direction nextDirection;


  Position& head();
  Position tail();

  bool isCollidingWithSelf();
};