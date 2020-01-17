#pragma once

#include "action.h"

#include "snake.h"
#include "pickup.h"

class MoveLeft : public Action
{
  Snake * snake;
  Pickup * pickup;

  public:

  MoveLeft(Snake &snake, Pickup &pickup);
  void call();

  private:

  bool isInBounds();
};