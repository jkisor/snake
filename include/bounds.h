#pragma once

#include "position.h"
struct Bounds
{
  int width;
  int height;

  bool contains(Position &p);
};
