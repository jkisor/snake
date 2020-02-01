#include "bounds.h"

bool Bounds::contains(Position &position)
{
  return position.y < height
    && position.x >= 0
    && position.x < width
    && position.y >= 0;
}
