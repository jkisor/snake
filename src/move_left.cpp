#include "move_left.h"
#include "direction.h"

MoveLeft::MoveLeft(Snake &snake, Pickup &pickup)
{
  this->snake = &snake;
  this->pickup = &pickup;
}

void MoveLeft::call()
{
  Direction direction = { -1, 0 };

  if( isInBounds() && (snake->positions[0].x + direction.x) != snake->positions[1].x )
  {

    Position oldEnd = snake->positions[snake->positions.size()-1];

    changePositions();

    if (isCollidingWithPickup())
      snake->positions.push_back(oldEnd);

  }
}

bool MoveLeft::isInBounds()
{
  return snake->positions[0].x > 0;
}

bool MoveLeft::isCollidingWithPickup()
{
  return snake->head().x == pickup->position.x && snake->head().y == pickup->position.y;
}

void MoveLeft::changePositions()
{
  Direction direction = { -1, 0 };

  for(int i = snake->positions.size()-1; i > 0; i--)
  {
    snake->positions[i].x = snake->positions[i-1].x;
    snake->positions[i].y = snake->positions[i-1].y;
  }

  snake->head() = { snake->head().x + direction.x, snake->head().y };
}
