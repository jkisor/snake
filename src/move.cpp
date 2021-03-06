#include "move.h"
#include "spawn_pickup.h"

Move::Move(State &state)
{
  this->state = &state;
}

void Move::call()
{
  Snake currentSnake = state->snake;
  Snake nextSnake = currentSnake.move();

  if(isOutOfBounds(nextSnake.head()) || nextSnake.isCollidingWithSelf())
    nextSnake = currentSnake.kill();

  if (isCollidingWithPickup(nextSnake.head()))
  {
    nextSnake = nextSnake.grow(currentSnake.tail());
    spawnPickup();
    state->score += 1;
  }

  state->snake = nextSnake;

}

bool Move::isOutOfBounds(Position &position)
{
  return !state->bounds.contains(position);
}

bool Move::isCollidingWithPickup(Position &position)
{
  return position == state->pickup.position;
}

void Move::spawnPickup()
{
  SpawnPickup(*state).call();
}

