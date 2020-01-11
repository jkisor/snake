#include "move_up.h"

MoveUp::MoveUp(Snake &snake)
{
  this->snake = &snake;
}

void MoveUp::call()
{
  if( snake->positions[0].y > 0 && (snake->positions[0].y - 1) != snake->positions[1].y)
  {

    snake->positions[2].x = snake->positions[1].x;
    snake->positions[2].y = snake->positions[1].y;

    snake->positions[1].x = snake->positions[0].x;
    snake->positions[1].y = snake->positions[0].y;


    snake->positions[0].y -= 1;
  }

}