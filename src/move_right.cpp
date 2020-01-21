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

  if(isInBounds() && (state->snake.head().x + direction.x) != state->snake.positions[1].x )
  {

    Position tail = state->snake.tail();

    state->snake = NextSnake().call(state->snake, direction);

    if (isCollidingWithPickup())
      state->snake.positions.push_back(tail);
  }
}

bool MoveRight::isInBounds()
{
  return state->snake.head().x < state->bounds.width-1;
}

bool MoveRight::isCollidingWithPickup()
{
  return state->snake.head().x == state->pickup.position.x && state->snake.head().y == state->pickup.position.y;
}