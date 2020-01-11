#pragma once

#include "action.h"

#include "snake.h"

class MoveLeft : public Action
{
  Snake * snake;

  public:

  MoveLeft(Snake &snake);
  void call();
};