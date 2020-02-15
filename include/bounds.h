#pragma once

#include "position.h"
#include "positions.h"
struct Bounds
{
  int width;
  int height;

  bool contains(Position &p);

  Positions positions();
};
