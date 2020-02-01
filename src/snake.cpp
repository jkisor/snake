#include "snake.h"

Position& Snake::head()
{
  return positions[0];
}

Position Snake::tail()
{
  return positions[positions.size()-1];
}

bool Snake::isCollidingWithSelf()
{
  return std::find(positions.begin()+1, positions.end(), head()) != positions.end();
}