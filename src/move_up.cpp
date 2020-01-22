#include "move_up.h"
#include "next_snake.h"
#include <cstdlib>

MoveUp::MoveUp(State &state)
{
  this->state = &state;
  this->direction = { 0, -1 };
}

void MoveUp::call()
{

  Snake currentSnake = state->snake;
  Snake nextSnake = NextSnake().call(currentSnake, direction);

  if( isInBounds(nextSnake) && nextSnake.head().y != state->snake.positions[1].y)
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

bool MoveUp::isInBounds(Snake &snake)
{
  return snake.positions[0].y >= 0;
}

bool MoveUp::isCollidingWithPickup(Snake &snake)
{
  return snake.head() == state->pickup.position;
}
