#pragma once

#include "action.h"
#include "snake.h"

class MoveUp : public Action
{
  Snake * snake;

  public:

  MoveUp(Snake &snake);
  void call();

  private:

  bool isInBounds();
};
