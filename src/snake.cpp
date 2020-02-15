#include "snake.h"

Position& Snake::head()
{
  return positions.all[0];
}

Position Snake::tail()
{
  return positions.last();
}

bool Snake::isCollidingWithSelf()
{
  return std::find(positions.all.begin()+1, positions.all.end(), head()) != positions.all.end();
}

Snake Snake::grow(Position p)
{
  Snake snake(*this);

  snake.positions.all.push_back(p);

  return snake;
}

Snake Snake::kill()
{
  Snake snake(*this);

  snake.dead = true;

  return snake;
}

Snake Snake::move()
  {
    Snake results(*this);

    // Positions
    std::vector<Position> updatedPositions;

    Position newHead = head().move(nextDirection);

    updatedPositions.push_back(newHead);

    for(int i = 0; i < positions.all.size()-1; i++)
      updatedPositions.push_back(positions.all[i]);

    results.positions = updatedPositions;

    // Direction
    results.currentDirection = nextDirection;

    return results;
  }