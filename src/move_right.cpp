#include "move_right.h"
#include "direction.h"
#include "next_snake.h"

MoveRight::MoveRight(Snake &snake, Bounds bounds, Pickup &pickup)
{
  this->snake = &snake;
  this->bounds = bounds;
  this->pickup = &pickup;
  this->direction = { 1, 0 };

}

void MoveRight::call()
{

  if(isInBounds() && (snake->head().x + direction.x) != snake->positions[1].x )
  {

    Position oldEnd = snake->positions[snake->positions.size()-1];

    Snake nextSnake = NextSnake().call(*snake, direction);
    snake->positions = nextSnake.positions;

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