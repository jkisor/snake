#include "move_up.h"
#include "next_snake.h"

MoveUp::MoveUp(State &state)
{
  this->state = &state;
  this->direction = { 0, -1 };
}

void MoveUp::call()
{

  Snake currentSnake = state->snake;
  Snake nextSnake = NextSnake().call(currentSnake, direction);

  if( isInBounds() && nextSnake.head().y != state->snake.positions[1].y)
  {

    if (isCollidingWithPickup(nextSnake))
      nextSnake.positions.push_back(currentSnake.tail());

    state->snake = nextSnake;
  }

}

bool MoveUp::isInBounds()
{
  return state->snake.positions[0].y > 0;
}

bool MoveUp::isCollidingWithPickup(Snake &snake)
{
  return snake.head().x == state->pickup.position.x && snake.head().y == state->pickup.position.y;
}
