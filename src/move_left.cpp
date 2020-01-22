#include "move_left.h"
#include "next_snake.h"

MoveLeft::MoveLeft(State &state)
{
  this->state = &state;
  this->direction = { -1, 0 };
}

void MoveLeft::call()
{

  Snake currentSnake = state->snake;
  Snake nextSnake = NextSnake().call(currentSnake, direction);

  if( isInBounds(nextSnake) && nextSnake.head().x != currentSnake.positions[1].x )
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

bool MoveLeft::isInBounds(Snake &snake)
{
  return snake.positions[0].x >= 0;
}

bool MoveLeft::isCollidingWithPickup(Snake &snake)
{
  return snake.head() == state->pickup.position;
}
