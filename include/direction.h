#pragma once

#define UP Direction({0,-1})
#define LEFT Direction({-1,0})
#define DOWN Direction({0,1})
#define RIGHT Direction({1,0})
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