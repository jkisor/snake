#include "spawn_pickup.h"

SpawnPickup::SpawnPickup(State &state)
{
  this->state = &state;
}

void SpawnPickup::call()
{
  Pickup nextPickup;
  nextPickup.position = { rand() % state->bounds.width, rand() % state->bounds.height };
  state->pickup = nextPickup;
}