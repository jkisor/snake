#pragma once

#include "action.h"
#include "snake.h"
#include "bounds.h"

class MoveRight : public Action
{
  Snake * snake;
  Bounds bounds;

  public:

  MoveRight(Snake &snake, Bounds bounds)
  {
    this->snake = &snake;
    this->bounds = bounds;
  }

  void call()
  {
    if( snake->positions[0].x < bounds.width-1 && (snake->positions[0].x + 1) != snake->positions[1].x )
    {

      snake->positions[2].x = snake->positions[1].x;
      snake->positions[2].y = snake->positions[1].y;

      snake->positions[1].x = snake->positions[0].x;
      snake->positions[1].y = snake->positions[0].y;

      snake->positions[0].x += 1;
    }
  }

};