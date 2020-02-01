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

  if(!isInBounds(nextSnake))
  {
    state->snake.dead = true;
  }
  else if(std::find(nextSnake.positions.begin()+1, nextSnake.positions.end(), nextSnake.head()) != nextSnake.positions.end())
  {
    state->snake.dead = true;
  }
  else
  {

    if (isCollidingWithPickup(nextSnake))
    {
      nextSnake.positions.push_back(currentSnake.tail());

      Pickup nextPickup;
      nextPickup.position = { rand() % state->bounds.width, rand() % state->bounds.height };
      state->pickup = nextPickup;
    }

    state->snake = nextSnake;

  }
}

bool Move::isInBounds(Snake &snake)
{
  Position head = snake.head();

  return head.y < state->bounds.height
    && head.x >= 0
    && head.x < state->bounds.width
    && head.y >= 0;
}

bool Move::isCollidingWithPickup(Snake &snake)
{
  return snake.head() == state->pickup.position;
}