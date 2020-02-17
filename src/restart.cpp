#include "restart.h"

Restart::Restart(State &state)
{
  this->state = &state;
}

void Restart::call()
{
  state->score = 0;
  state->snake.positions = Positions({ {2,0}, {1,0}, {0,0} });

  state->snake.dead = false;
  state->snake.nextDirection = { 1, 0 };
  state->snake.currentDirection = { 1, 0 };

  state->pickup.position = { 5, 4 };

  state->countdown = Countdown(3.0f);
}