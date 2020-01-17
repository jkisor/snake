#pragma once

#include "action.h"
#include "snake.h"
#include "pickup.h"

class MoveUp : public Action
{
  Snake * snake;
  Pickup * pickup;

  public:

  MoveUp(Snake &snake, Pickup &pickup);
  void call();

  private:

  bool isInBounds();
};
