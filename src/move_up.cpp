#include "move_up.h"
#include "direction.h"

MoveUp::MoveUp(Snake &snake, Pickup &pickup)
{
  this->snake = &snake;
  this->pickup = &pickup;
}

void MoveUp::call()
{
  Direction direction = { 0, -1 };

  if( isInBounds() && (snake->positions[0].y + direction.y) != snake->positions[1].y)
  {

    Position oldEnd = snake->positions[snake->positions.size()-1];
    Position newHead = { snake->head().x, snake->head().y + direction.y};

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


bool MoveUp::isInBounds()
{
  return snake->positions[0].y > 0;
}