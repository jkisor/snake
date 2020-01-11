#pragma once

#include "action.h"
#include "snake.h"
#include "bounds.h"

class MoveRight : public Action
{
  Snake * snake;
  Bounds bounds;

  public:

  MoveRight(Snake &snake, Bounds bounds);
  void call();

};