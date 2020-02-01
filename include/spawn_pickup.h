#pragma once

#include "state.h"
#include "pickup.h"

class SpawnPickup
{
  State * state;

  public:

  SpawnPickup(State &state);
  void call();
};