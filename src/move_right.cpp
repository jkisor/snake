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

  if(isInBounds(nextSnake) && nextSnake.head().x != currentSnake.positions[1].x )
  {

    if (isCollidingWithPickup(nextSnake))
      nextSnake.positions.push_back(currentSnake.tail());

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