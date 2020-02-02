#include "next_snake.h"
#include "direction.h"

Snake NextSnake::call(Snake &snake)
{
  Snake results;

  std::vector<Position> positions;

  Position head = snake.head().move(snake.nextDirection);

  results.currentDirection = snake.nextDirection;
  results.nextDirection = snake.nextDirection;

  positions.push_back(head);

  for(int i = 0; i < snake.positions.size()-1; i++)
    positions.push_back(snake.positions[i]);

  results.positions = positions;

  return results;
};
