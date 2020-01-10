#pragma once

#include "action.h"
#include "snake.h"

class MoveRight : public Action
{
  Snake * snake;

  public:

  MoveRight(Snake &snake)
  {
    this->snake = &snake;
  }

  void call()
  {
    if( snake->positions[0].x < BOUNDS_WIDTH-1 && (snake->positions[0].x + 1) != snake->positions[1].x )
    {

      snake->positions[2].x = snake->positions[1].x;
      snake->positions[2].y = snake->positions[1].y;

      snake->positions[1].x = snake->positions[0].x;
      snake->positions[1].y = snake->positions[0].y;

      snake->positions[0].x += 1;
    }
  }

};