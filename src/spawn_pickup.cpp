#include "spawn_pickup.h"
#include "positions.h"

SpawnPickup::SpawnPickup(State &state)
{
  this->state = &state;
}

void SpawnPickup::call()
{
  Positions positions;

  for(int y = 0; y < state->bounds.height; y++)
    for(int x = 0; x < state->bounds.width; x++)
      positions.all.push_back({x,y});

  Positions invalidPositions(state->snake.positions);

  Positions validPositions = positions.except(invalidPositions);

  Pickup nextPickup;
  nextPickup.position = validPositions.all[rand() % validPositions.all.size()];
  state->pickup = nextPickup;
}