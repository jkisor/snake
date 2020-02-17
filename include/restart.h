#pragma once

#include "action.h"
#include "state.h"

class Restart : public Action
{
  State * state;

  public:

  Restart(State &state);
  void call();

};