#pragma once

#include "action.h"
#include "state.h"
#include "direction.h"

class MoveDown : public Action
{
  State * state;
  Direction direction;

  public:

  MoveDown(State &state);
  void call();

  private:

  bool isInBounds(Snake &snake);
  bool isCollidingWithPickup(Snake &snake);

};