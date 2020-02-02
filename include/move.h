#pragma once

#include "action.h"
#include "state.h"
#include "direction.h"

class Move : public Action
{
  State * state;
  Direction direction;

  public:

  Move(State &state);
  void call();

  private:

  bool isOutOfBounds(Position &position);
  bool isCollidingWithPickup(Position &position);
  void spawnPickup();


};