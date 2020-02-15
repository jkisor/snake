#include "bounds.h"

bool Bounds::contains(Position &position)
{
  return position.y < height
    && position.x >= 0
    && position.x < width
    && position.y >= 0;
}

Positions Bounds::positions()
{
  Positions results;

  for(int y = 0; y < height; y++)
    for(int x = 0; x < width; x++)
      results.all.push_back({x,y});

  return results;
}
