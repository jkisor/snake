#pragma once

#include <vector>
#include "position.h"
#include "direction.h"

struct Snake
{
  std::vector<Position> positions;

  Direction currentDirection;
  Direction nextDirection;


  Position& head();
  Position tail();
};