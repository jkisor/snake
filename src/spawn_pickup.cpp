#include "spawn_pickup.h"
#include <algorithm>
#include <vector>

SpawnPickup::SpawnPickup(State &state)
{
  this->state = &state;
}

void SpawnPickup::call()
{

  std::vector<Position> positions;

  for(int y = 0; y < state->bounds.height; y++)
  {
    for(int x = 0; x < state->bounds.width; x++)
    {
      std::vector<Position> snakePos = state->snake.positions;

      if (std::find(snakePos.begin(), snakePos.end(), Position({x,y})) == snakePos.end())
        positions.push_back({x,y});

    }
  };

  Pickup nextPickup;
  nextPickup.position = positions[rand() % positions.size()];
  state->pickup = nextPickup;
}