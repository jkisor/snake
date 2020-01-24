#pragma once

#include "action.h"
#include "state.h"

class ChangeDirection : public Action
{
  State * state;
  Direction direction;

  public:

  ChangeDirection(State &state, Direction direction);
  void call();
};