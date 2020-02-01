#include "move.h"
#include "next_snake.h"

Move::Move(State &state)
{
  this->state = &state;
}

void Move::call()
{
  Snake currentSnake = state->snake;
  Snake nextSnake = NextSnake().call(currentSnake);

  if(!isInBounds(nextSnake.head()) || isCollidingWithSelf(nextSnake))
    state->snake.dead = true;
  else
  {

    if (isCollidingWithPickup(nextSnake.head()))
    {
      nextSnake.positions.push_back(currentSnake.tail());
      spawnPickup();
    }

    state->snake = nextSnake;

  }
}

bool Move::isInBounds(Position &position)
{
  return position.y < state->bounds.height
    && position.x >= 0
    && position.x < state->bounds.width
    && position.y >= 0;
}

bool Move::isCollidingWithSelf(Snake &snake)
{
  return std::find(snake.positions.begin()+1, snake.positions.end(), snake.head()) != snake.positions.end();
}

bool Move::isCollidingWithPickup(Position &position)
{
  return position == state->pickup.position;
}

void Move::spawnPickup()
{
  Pickup nextPickup;
  nextPickup.position = { rand() % state->bounds.width, rand() % state->bounds.height };
  state->pickup = nextPickup;
}

