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

  if(isInBounds(nextSnake) && nextSnake.head() != currentSnake.positions[1] )
  {

    if (isCollidingWithPickup(nextSnake))
    {
      nextSnake.positions.push_back(currentSnake.tail());
      Direction d = currentSnake.directions[currentSnake.directions.size()-1];
      nextSnake.directions.push_back(d);

      Pickup nextPickup;
      nextPickup.position = { rand() % state->bounds.width, rand() % state->bounds.height };
      state->pickup = nextPickup;
    }

    state->snake = nextSnake;

  }
}

bool Move::isInBounds(Snake &snake)
{
  return snake.head().y < state->bounds.height
    && snake.head().x >= 0
    && snake.head().x < state->bounds.width
    && snake.head().y >= 0;
}

bool Move::isCollidingWithPickup(Snake &snake)
{
  return snake.head() == state->pickup.position;
}