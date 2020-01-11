#include "move_down.h"

MoveDown::MoveDown(Snake &snake, Bounds bounds)
{
  this->snake = &snake;
  this->bounds = bounds;
}

void MoveDown::call()
{
  if( snake->positions[0].y < bounds.height-1 && (snake->positions[0].y + 1) != snake->positions[1].y )
  {

    snake->positions[2].x = snake->positions[1].x;
    snake->positions[2].y = snake->positions[1].y;

    snake->positions[1].x = snake->positions[0].x;
    snake->positions[1].y = snake->positions[0].y;

    snake->positions[0].y += 1;
  }

}
