#include "snake.h"

Position& Snake::head()
{
  return positions[0];
}

Position Snake::tail()
{
  return positions[positions.size()-1];
}

bool Snake::isCollidingWithSelf()
{
  return std::find(positions.begin()+1, positions.end(), head()) != positions.end();
}

Snake Snake::grow(Position p)
{
  Snake snake(*this);

  snake.positions.push_back(p);

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

    updatedPositions.push_back(head().move(nextDirection));

    for(int i = 0; i < positions.size()-1; i++)
      updatedPositions.push_back(positions[i]);

    results.positions = updatedPositions;

    // Direction
    results.currentDirection = nextDirection;

    return results;
  }