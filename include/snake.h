#pragma once

#include <vector>
#include "position.h"
#include "direction.h"

struct Snake
{
  std::vector<Position> positions;
  std::vector<Direction> directions;

  Direction direction;


  Position& head();
  Position tail();
};