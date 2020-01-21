#include "move_left.h"
#include "next_snake.h"

MoveLeft::MoveLeft(State &state)
{
  this->state = &state;
  this->direction = { -1, 0 };
}

void MoveLeft::call()
{

  if( isInBounds() && (state->snake.positions[0].x + direction.x) != state->snake.positions[1].x )
  {

    Position tail = state->snake.tail();

    state->snake = NextSnake().call(state->snake, direction);

    if (isCollidingWithPickup())
      state->snake.positions.push_back(tail);

  }
}

bool MoveLeft::isInBounds()
{
  return state->snake.positions[0].x > 0;
}

bool MoveLeft::isCollidingWithPickup()
{
  return state->snake.head().x == state->pickup.position.x && state->snake.head().y == state->pickup.position.y;
}
