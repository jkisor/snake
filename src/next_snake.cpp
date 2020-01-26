#include "next_snake.h"
#include "direction.h"

Snake NextSnake::call(Snake &snake)
{
  Snake results;

  std::vector<Position> positions;

  Position pos;
  pos.x = snake.head().x + snake.nextDirection.x;
  pos.y = snake.head().y + snake.nextDirection.y;

  positions.push_back(pos);

  Direction dir;
  dir.x = pos.x - snake.positions[0].x;
  dir.y = pos.y - snake.positions[0].y;

  results.currentDirection = snake.nextDirection;
  results.nextDirection = snake.nextDirection;

  for(int i = 0; i < snake.positions.size()-1; i++)
    positions.push_back(snake.positions[i]);

  results.positions = positions;

  return results;
};
