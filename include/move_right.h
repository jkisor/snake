#pragma once

#include "action.h"
#include "snake.h"
#include "bounds.h"
#include "pickup.h"

class MoveRight : public Action
{
  Snake * snake;
  Bounds bounds;
  Pickup * pickup;

  public:

  MoveRight(Snake &snake, Bounds bounds, Pickup &pickup);
  void call();

};