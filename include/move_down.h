#pragma once

#include "action.h"
#include "snake.h"
#include "bounds.h"

class MoveDown : public Action
{
  Snake * snake;
  Bounds bounds;

  public:

  MoveDown(Snake &snake, Bounds bounds);
  void call();

  private:

  bool isInBounds();

};