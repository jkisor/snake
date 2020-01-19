#include "move_down.h"
#include "direction.h"

MoveDown::MoveDown(Snake &snake, Bounds bounds, Pickup &pickup)
{
  this->snake = &snake;
  this->bounds = bounds;
  this->pickup = &pickup;
}

void MoveDown::call()
{

  Direction direction = { 0, 1 };

  if( isInBounds() && (snake->positions[0].y + direction.y) != snake->positions[1].y )
  {
    Position oldEnd = snake->positions[snake->positions.size()-1];

    changePositions();

    if (isCollidingWithPickup())
      snake->positions.push_back(oldEnd);

  }

}

bool MoveDown::isInBounds()
{
  return snake->positions[0].y < bounds.height-1;
}

bool MoveDown::isCollidingWithPickup()
{
  return snake->head().x == pickup->position.x && snake->head().y == pickup->position.y;
}

void MoveDown::changePositions()
{
  Direction direction = { 0, 1 };

  for(int i = snake->positions.size()-1; i > 0; i--)
  {
    snake->positions[i].x = snake->positions[i-1].x;
    snake->positions[i].y = snake->positions[i-1].y;
  }

  snake->head() = { snake->head().x, snake->head().y + direction.y};
}

