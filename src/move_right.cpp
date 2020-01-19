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
    
    changePositions();

    if (isCollidingWithPickup())
      snake->positions.push_back(oldEnd);
  }
}

bool MoveRight::isInBounds()
{
  return snake->head().x < bounds.width-1;
}

bool MoveRight::isCollidingWithPickup()
{
  return snake->head().x == pickup->position.x && snake->head().y == pickup->position.y;
}

void MoveRight::changePositions()
{
  Direction direction = { 1, 0 };

  for(int i = snake->positions.size()-1; i > 0; i--)
  {
    snake->positions[i].x = snake->positions[i-1].x;
    snake->positions[i].y = snake->positions[i-1].y;
  }

  snake->head() = { snake->head().x + direction.x, snake->head().y};
}
