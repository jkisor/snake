// tests-factorial.cpp
#include "catch.hpp"
#include "next_snake.h"

TEST_CASE( "it works")
{
  Snake snake;
  snake.positions = { {2,0}, {1,0}, {0,0} };
  snake.nextDirection = { 1, 0 };

  NextSnake nextSnake;
  Snake results = nextSnake.call(snake);

  std::vector<Position> expected = { {3,0}, {2,0}, {1,0} };

  // Not using Position == operator so we can see diff in fail message
  REQUIRE( results.positions[0].x == expected[0].x );
  REQUIRE( results.positions[0].y == expected[0].y );

  REQUIRE( results.positions[1].x == expected[1].x );
  REQUIRE( results.positions[1].y == expected[1].y );

  REQUIRE( results.positions[2].x == expected[2].x );
  REQUIRE( results.positions[2].y == expected[2].y );


};