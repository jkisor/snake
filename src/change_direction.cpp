#include "change_direction.h"

ChangeDirection::ChangeDirection(State &state, Direction direction)
{
  this->state = &state;
  this->direction = direction;
}

void ChangeDirection::call()
{
  state->snake.nextDirection = direction;
}