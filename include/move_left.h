#pragma once

#include "action.h"

#include "snake.h"
#include "pickup.h"
#include "direction.h"

class MoveLeft : public Action
{
  Snake * snake;
  Pickup * pickup;
  Direction direction;


  public:

  MoveLeft(Snake &snake, Pickup &pickup);
  void call();

  private:

  bool isInBounds();
  bool isCollidingWithPickup();
  std::vector<Position> nextPositions();

};