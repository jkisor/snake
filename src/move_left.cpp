#include "move_left.h"

MoveLeft::MoveLeft(Snake &snake)
{
  this->snake = &snake;
}

void MoveLeft::call()
{
  if( snake->positions[0].x > 0 && (snake->positions[0].x - 1) != snake->positions[1].x )
  {

    for(int i = snake->positions.size()-1; i > 0; i--)
    {
      snake->positions[i].x = snake->positions[i-1].x;
      snake->positions[i].y = snake->positions[i-1].y;
    }
    
    snake->positions[0].x -= 1;
  }
}