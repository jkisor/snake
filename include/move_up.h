#pragma once

#include "action.h"
#include "snake.h"
#include "pickup.h"
#include "direction.h"

class MoveUp : public Action
{
  Snake * snake;
  Pickup * pickup;
  Direction direction;

  public:

  MoveUp(Snake &snake, Pickup &pickup);
  void call();

  private:

  bool isInBounds();
  bool isCollidingWithPickup();
  std::vector<Position> nextPositions();

};
