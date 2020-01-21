#include "move_up.h"
#include "next_snake.h"

MoveUp::MoveUp(State &state)
{
  this->state = &state;
  this->direction = { 0, -1 };
}

void MoveUp::call()
{

  if( isInBounds() && (state->snake.positions[0].y + direction.y) != state->snake.positions[1].y)
  {

    Position oldEnd = state->snake.positions[state->snake.positions.size()-1];
    state->snake = NextSnake().call(state->snake, direction);

    if (isCollidingWithPickup())
      state->snake.positions.push_back(oldEnd);
  }

}

bool MoveUp::isInBounds()
{
  return state->snake.positions[0].y > 0;
}

bool MoveUp::isCollidingWithPickup()
{
  return state->snake.head().x == state->pickup.position.x && state->snake.head().y == state->pickup.position.y;
}
