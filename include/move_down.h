#pragma once

#include "action.h"
#include "snake.h"

class MoveDown : public Action
{
  Snake * snake;

  public:

  MoveDown(Snake &snake)
  {
    this->snake = &snake;
  }

  void call()
  {
    if( snake->positions[0].y < BOUNDS_HEIGHT-1 && (snake->positions[0].y + 1) != snake->positions[1].y )
    {

      snake->positions[2].x = snake->positions[1].x;
      snake->positions[2].y = snake->positions[1].y;

      snake->positions[1].x = snake->positions[0].x;
      snake->positions[1].y = snake->positions[0].y;

      snake->positions[0].y += 1;
    }

  }

};