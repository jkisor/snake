#include "move_up.h"

MoveUp::MoveUp(Snake &snake)
{
  this->snake = &snake;
}

void MoveUp::call()
{
  if( snake->positions[0].y > 0 && (snake->positions[0].y - 1) != snake->positions[1].y)
  {

    for(int i = snake->positions.size()-1; i > 0; i--)
    {
      snake->positions[i].x = snake->positions[i-1].x;
      snake->positions[i].y = snake->positions[i-1].y;
    }

    snake->positions[0].y -= 1;
  }

}