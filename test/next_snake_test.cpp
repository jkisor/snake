// tests-factorial.cpp
#include "catch.hpp"
#include "next_snake.h"

TEST_CASE( "it works")
{
  Snake snake;
  snake.positions = { {2,0}, {1,0}, {0,0} };

  Direction direction = { 1, 0 };

  NextSnake nextSnake;
  Snake results = nextSnake.call(snake, direction);

  std::vector<Position> expected = { {3,0}, {2,0}, {1,0} };

  REQUIRE( results.positions == expected );
};