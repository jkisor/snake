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

  if( isInBounds() && (state->snake.positions[0].y + direction.y) != state->snake.positions[1].y )
  {
    Position oldEnd = state->snake.positions[state->snake.positions.size()-1];

    Snake nextSnake = NextSnake().call(state->snake, direction);
    state->snake = nextSnake;

    if (isCollidingWithPickup())
      state->snake.positions.push_back(oldEnd);

  }

}

bool MoveDown::isInBounds()
{
  return state->snake.positions[0].y < state->bounds.height-1;
}

bool MoveDown::isCollidingWithPickup()
{
  return state->snake.head().x == state->pickup.position.x && state->snake.head().y == state->pickup.position.y;
}


