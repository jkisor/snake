#include "next_snake.h"
#include "direction.h"

Snake NextSnake::call(Snake &snake)
{
  Snake results;

  std::vector<Position> positions;
  std::vector<Direction> directions;

  Position pos;
  pos.x = snake.head().x + snake.direction.x;
  pos.y = snake.head().y + snake.direction.y;

  positions.push_back(pos);

  Direction dir;
  dir.x = pos.x - snake.positions[0].x;
  dir.y = pos.y - snake.positions[0].y;

  directions.push_back(dir);

  for(int i = 0; i < snake.positions.size()-1; i++)
  {
    positions.push_back(snake.positions[i]);
    directions.push_back(snake.directions[i]);
  }

  results.positions = positions;
  results.directions = directions;

  results.direction = snake.direction;
  return results;
};
