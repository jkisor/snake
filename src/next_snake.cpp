#include "next_snake.h"

Snake NextSnake::call(Snake &snake)
{
  Snake results;

  std::vector<Position> positions;

  positions.push_back({ snake.head().x + snake.direction.x, snake.head().y + snake.direction.y});

  for(int i = 0; i < snake.positions.size() - 1; i++)
    positions.push_back(snake.positions[i]);

  results.positions = positions;

  return results;
};
