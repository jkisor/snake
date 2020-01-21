#include "snake.h"

Position& Snake::head()
{
  return positions[0];
}

Position Snake::tail()
{
  return positions[positions.size()-1];
}
