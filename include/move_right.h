#pragma once

#include "action.h"
#include "snake.h"
#include "bounds.h"
#include "pickup.h"
#include "direction.h"

class MoveRight : public Action
{
  Snake * snake;
  Bounds bounds;
  Pickup * pickup;
  Direction direction;

  public:

  MoveRight(Snake &snake, Bounds bounds, Pickup &pickup);
  void call();

  private:

  bool isInBounds();
  bool isCollidingWithPickup();


};