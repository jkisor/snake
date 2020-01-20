#pragma once

struct Position
{
  int x;
  int y;

  bool operator==(const Position &p) const
  {
    return x == p.x && y == p.y;
  };
};