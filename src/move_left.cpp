#include "move_left.h"

MoveLeft::MoveLeft(Snake &snake)
{
  this->snake = &snake;
}

void MoveLeft::call()
{
  if( snake->positions[0].x > 0 && (snake->positions[0].x - 1) != snake->positions[1].x )
  {

    snake->positions[2].x = snake->positions[1].x;
    snake->positions[2].y = snake->positions[1].y;

    snake->positions[1].x = snake->positions[0].x;
    snake->positions[1].y = snake->positions[0].y;

    snake->positions[0].x -= 1;
  }
}