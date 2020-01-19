#pragma once

#include "action.h"
#include "snake.h"
#include "bounds.h"
#include "pickup.h"

class MoveDown : public Action
{
  Snake * snake;
  Bounds bounds;
  Pickup * pickup;

  public:

  MoveDown(Snake &snake, Bounds bounds, Pickup &pickup);
  void call();

  private:

  bool isInBounds();
  bool isCollidingWithPickup();
  void changePositions();

};