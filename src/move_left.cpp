#include "move_left.h"
#include "direction.h"
#include "next_snake.h"

MoveLeft::MoveLeft(Snake &snake, Pickup &pickup)
{
  this->snake = &snake;
  this->pickup = &pickup;
  this->direction = { -1, 0 };

}

void MoveLeft::call()
{

  if( isInBounds() && (snake->positions[0].x + direction.x) != snake->positions[1].x )
  {

    Position oldEnd = snake->positions[snake->positions.size()-1];


    Snake nextSnake = NextSnake().call(*snake, direction);
    snake->positions = nextSnake.positions;

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
