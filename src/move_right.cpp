#include "move_right.h"

MoveRight::MoveRight(Snake &snake, Bounds bounds, Pickup &pickup)
{
  this->snake = &snake;
  this->bounds = bounds;
  this->pickup = &pickup;
}

void MoveRight::call()
{
  if( snake->positions[0].x < bounds.width-1 && (snake->positions[0].x + 1) != snake->positions[1].x )
  {

    Position oldEnd = snake->positions[2];

    Position newHead = { snake->positions[0].x + 1, snake->positions[0].y };

    snake->positions[2].x = snake->positions[1].x;
    snake->positions[2].y = snake->positions[1].y;

    snake->positions[1].x = snake->positions[0].x;
    snake->positions[1].y = snake->positions[0].y;

    snake->positions[0] = newHead;

    if (newHead.x == pickup->position.x && newHead.y == pickup->position.y)
      snake->positions.push_back(oldEnd);

  }
}