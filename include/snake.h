#pragma once

#include <vector>
#include "position.h"

struct Snake
{
  std::vector<Position> positions;

  Position& head();
};