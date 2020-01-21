#pragma once

#include "action.h"
#include "state.h"
#include "direction.h"

class MoveLeft : public Action
{
  State * state;
  Direction direction;

  public:

  MoveLeft(State &state);
  void call();

  private:

  bool isInBounds(Snake &snake);
  bool isCollidingWithPickup(Snake &snake);

};