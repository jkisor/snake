#include "move_up.h"
#include "direction.h"

MoveUp::MoveUp(Snake &snake, Pickup &pickup)
{
  this->snake = &snake;
  this->pickup = &pickup;
  this->direction = { 0, -1 };
}

void MoveUp::call()
{

  if( isInBounds() && (snake->positions[0].y + direction.y) != snake->positions[1].y)
  {

    Position oldEnd = snake->positions[snake->positions.size()-1];
    changePositions();

    if (isCollidingWithPickup())
      snake->positions.push_back(oldEnd);
  }

}

bool MoveUp::isInBounds()
{
  return snake->positions[0].y > 0;
}

bool MoveUp::isCollidingWithPickup()
{
  return snake->head().x == pickup->position.x && snake->head().y == pickup->position.y;
}

void MoveUp::changePositions()
{
  for(int i = snake->positions.size()-1; i > 0; i--)
  {
    snake->positions[i].x = snake->positions[i-1].x;
    snake->positions[i].y = snake->positions[i-1].y;
  }

  snake->head() = { snake->head().x, snake->head().y + direction.y};
}
