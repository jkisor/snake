#include "spawn_pickup.h"
#include "positions.h"

SpawnPickup::SpawnPickup(State &state)
{
  this->state = &state;
}

void SpawnPickup::call()
{

  Positions positions = state->bounds.positions().except(Positions(state->snake.positions));

  Pickup nextPickup;
  nextPickup.position = positions.random();
  state->pickup = nextPickup;
}