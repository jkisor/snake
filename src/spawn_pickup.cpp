#include "spawn_pickup.h"
#include "positions.h"

SpawnPickup::SpawnPickup(State &state)
{
  this->state = &state;
}

void SpawnPickup::call()
{

  Positions invalidPositions(state->snake.positions);

  Positions validPositions = state->bounds.positions().except(invalidPositions);

  Pickup nextPickup;
  nextPickup.position = validPositions.all[rand() % validPositions.all.size()];
  state->pickup = nextPickup;
}