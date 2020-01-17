#include "move_up.h"
#include "direction.h"

MoveUp::MoveUp(Snake &snake)
{
  this->snake = &snake;
}

void MoveUp::call()
{
  Direction direction = { 0, -1 };

  if( isInBounds() && (snake->positions[0].y + direction.y) != snake->positions[1].y)
  {

    for(int i = snake->positions.size()-1; i > 0; i--)
    {
      snake->positions[i].x = snake->positions[i-1].x;
      snake->positions[i].y = snake->positions[i-1].y;
    }

    snake->positions[0].y += direction.y;
  }

}


bool MoveUp::isInBounds()
{
  return snake->positions[0].y > 0;
}