#include "spawn_pickup.h"
#include <algorithm>
#include <vector>

SpawnPickup::SpawnPickup(State &state)
{
  this->state = &state;
}

void SpawnPickup::call()
{

  std::vector<Position> allPositions;

  for(int y = 0; y < state->bounds.height; y++)
    for(int x = 0; x < state->bounds.width; x++)
      allPositions.push_back({x,y});

  std::vector<Position> invalidPositions = state->snake.positions;
  std::vector<Position> validPositions;

  std::copy_if(
    allPositions.begin(),
    allPositions.end(),
    std::back_inserter(validPositions),
    [invalidPositions](Position p) { return std::find(invalidPositions.begin(), invalidPositions.end(), p) == invalidPositions.end(); } // not found
  );

  Pickup nextPickup;
  nextPickup.position = validPositions[rand() % validPositions.size()];
  state->pickup = nextPickup;
}