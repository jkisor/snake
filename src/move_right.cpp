#include "move_right.h"
#include "direction.h"

MoveRight::MoveRight(Snake &snake, Bounds bounds, Pickup &pickup)
{
  this->snake = &snake;
  this->bounds = bounds;
  this->pickup = &pickup;
}

void MoveRight::call()
{
  Direction direction = { 1, 0 };

  if(isInBounds() && (snake->head().x + direction.x) != snake->positions[1].x )
  {

    Position oldEnd = snake->positions[snake->positions.size()-1];
    Position newHead = { snake->head().x + direction.x, snake->head().y };

    for(int i = snake->positions.size()-1; i > 0; i--)
    {
      snake->positions[i].x = snake->positions[i-1].x;
      snake->positions[i].y = snake->positions[i-1].y;
    }

    snake->head() = newHead;

    if (newHead.x == pickup->position.x && newHead.y == pickup->position.y)
      snake->positions.push_back(oldEnd);

  }
}

bool MoveRight::isInBounds()
{
  return snake->head().x < bounds.width-1;
}