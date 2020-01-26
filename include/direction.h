#pragma once

struct Direction
{
  int x;
  int y;

  bool operator==(const Direction &other) const
  {
    return x == other.x && y == other.y;
  };

  bool operator!=(const Direction &other) const
  {
    return x != other.x || y != other.y;
  };

};