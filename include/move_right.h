#pragma once

#include "action.h"
#include "state.h"
#include "direction.h"

class MoveRight : public Action
{
  State * state;
  Direction direction;

  public:

  MoveRight(State &state);
  void call();

  private:

  bool isInBounds(Snake &snake);
  bool isCollidingWithPickup(Snake &snake);


};