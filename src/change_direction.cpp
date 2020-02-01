#include "change_direction.h"

ChangeDirection::ChangeDirection(State &state, Direction direction)
{
  this->state = &state;
  this->direction = direction;
}

void ChangeDirection::call()
{
  Position currentHead = state->snake.head();

  Position pos;
  pos.x = currentHead.x + direction.x;
  pos.y = currentHead.y + direction.y;


  // Valid
  if(pos != state->snake.positions[1])
    state->snake.nextDirection = direction;

}