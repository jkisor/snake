#include "move_right.h"
#include "direction.h"
#include "next_snake.h"

MoveRight::MoveRight(State &state)
{
  this->state = &state;
  this->direction = { 1, 0 };

}

void MoveRight::call()
{
  Snake currentSnake = state->snake;
  Snake nextSnake = NextSnake().call(currentSnake, direction);

  if(isInBounds(nextSnake) && nextSnake.head() != currentSnake.positions[1] )
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

bool MoveRight::isInBounds(Snake &snake)
{
  return snake.head().x < state->bounds.width;
}

bool MoveRight::isCollidingWithPickup(Snake &snake)
{
  return snake.head() == state->pickup.position;
}