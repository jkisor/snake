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

  if( isInBounds(nextSnake) && nextSnake.head() != currentSnake.positions[1])
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
  return snake.head().y < state->bounds.height
    && snake.head().x >= 0
    && snake.head().x < state->bounds.width
    && snake.head().y >= 0;
}

bool MoveUp::isCollidingWithPickup(Snake &snake)
{
  return snake.head() == state->pickup.position;
}
