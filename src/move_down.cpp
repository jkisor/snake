#include "move_down.h"
#include "direction.h"
#include "next_snake.h"

MoveDown::MoveDown(Snake &snake, Bounds bounds, Pickup &pickup)
{
  this->snake = &snake;
  this->bounds = bounds;
  this->pickup = &pickup;
  this->direction = { 0, 1 };
}

void MoveDown::call()
{

  if( isInBounds() && (snake->positions[0].y + direction.y) != snake->positions[1].y )
  {
    Position oldEnd = snake->positions[snake->positions.size()-1];

    Snake nextSnake = NextSnake().call(*snake, direction);
    snake->positions = nextSnake.positions;

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


