#include "move.h"
#include "spawn_pickup.h"

Move::Move(State &state)
{
  this->state = &state;
}

void Move::call()
{
  Snake currentSnake = state->snake;
  Snake nextSnake = currentSnake.next();

  if(!isInBounds(nextSnake.head()) || nextSnake.isCollidingWithSelf())
    nextSnake = currentSnake.kill();

  if (isCollidingWithPickup(nextSnake.head()))
  {
    nextSnake = nextSnake.add(currentSnake.tail());
    spawnPickup();
  }

  state->snake = nextSnake;

}

bool Move::isInBounds(Position &position)
{
  return state->bounds.contains(position);
}

bool Move::isCollidingWithPickup(Position &position)
{
  return position == state->pickup.position;
}

void Move::spawnPickup()
{
  SpawnPickup(*state).call();
}

