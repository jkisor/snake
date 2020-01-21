#pragma once

#include "action.h"
#include "state.h"
#include "direction.h"

class MoveUp : public Action
{
  State * state;
  Direction direction;

  public:

  MoveUp(State &state);
  void call();

  private:

  bool isInBounds();
  bool isCollidingWithPickup(Snake &snake);

};
