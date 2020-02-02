#pragma once

#include "direction.h"

struct Position
{
  int x;
  int y;

  bool operator==(const Position &p) const
  {
    return x == p.x && y == p.y;
  };

  bool operator!=(const Position &p) const
  {
    return x != p.x || y != p.y;
  };

  Position move(Direction direction)
  {
    Position position(*this);

    position.x = x + direction.x;
    position.y = y + direction.y;

    return position;
  }

};