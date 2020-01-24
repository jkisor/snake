#pragma once

#include <vector>
#include "position.h"
#include "direction.h"

struct Snake
{
  std::vector<Position> positions;
  Direction direction;

  Position& head();
  Position tail();
};