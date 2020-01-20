#include "move_down.h"
#include "direction.h"

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

    snake->positions = nextPositions();

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

std::vector<Position> MoveDown::nextPositions()
{
  std::vector<Position> results;

  results.push_back({ snake->head().x + direction.x, snake->head().y + direction.y});

  for(int i = 0; i < snake->positions.size() - 1; i++)
    results.push_back(snake->positions[i]);

  return results;

}

