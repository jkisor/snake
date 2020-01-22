#include "move_down.h"
#include "direction.h"
#include "next_snake.h"

MoveDown::MoveDown(State &state)
{
  this->state = &state;
  this->direction = { 0, 1 };
}

void MoveDown::call()
{

  Snake currentSnake = state->snake;
  Snake nextSnake = NextSnake().call(currentSnake, direction);

  if( isInBounds(nextSnake) && nextSnake.head() != currentSnake.positions[1] )
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

bool MoveDown::isInBounds(Snake &snake)
{
  return snake.head().y < state->bounds.height;
}

bool MoveDown::isCollidingWithPickup(Snake &snake)
{
  return snake.head() == state->pickup.position;
}


