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

  if( isInBounds() && nextSnake.head().y != currentSnake.positions[1].y )
  {
    if (isCollidingWithPickup(nextSnake))
      nextSnake.positions.push_back(currentSnake.tail());

    state->snake = nextSnake;

  }

}

bool MoveDown::isInBounds()
{
  return state->snake.positions[0].y < state->bounds.height-1;
}

bool MoveDown::isCollidingWithPickup(Snake &snake)
{
  return snake.head().x == state->pickup.position.x && snake.head().y == state->pickup.position.y;
}


