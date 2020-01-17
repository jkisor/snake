#include "move_down.h"
#include "direction.h"

MoveDown::MoveDown(Snake &snake, Bounds bounds)
{
  this->snake = &snake;
  this->bounds = bounds;
}

void MoveDown::call()
{

  Direction direction = { 0, 1 };

  if( isInBounds() && (snake->positions[0].y + direction.y) != snake->positions[1].y )
  {

    for(int i = snake->positions.size()-1; i > 0; i--)
    {
      snake->positions[i].x = snake->positions[i-1].x;
      snake->positions[i].y = snake->positions[i-1].y;
    }

    snake->positions[0].y += direction.y;
  }

}

bool MoveDown::isInBounds()
{
  return snake->positions[0].y < bounds.height-1;
}
