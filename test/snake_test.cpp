#include "catch.hpp"
#include "snake.h"

TEST_CASE("test colliding with self")
{
  Snake straightSnake;
  straightSnake.positions = {{2,0}, {1,0}, {0,0}};

  REQUIRE(!straightSnake.isCollidingWithSelf());

  Snake overlappingSnake;
  overlappingSnake.positions = {{2,0}, {2,1}, {3,1}, {3,0}, {2,0}, {1,0}, {0,0}};

  REQUIRE(overlappingSnake.isCollidingWithSelf());

}

TEST_CASE("growing snake")
{
  Position p = {0,0};
  Snake snake;

  Snake result = snake.grow({0,0});

  REQUIRE(result.tail() == p);
}

TEST_CASE("killing snake")
{
  Snake snake;

  Snake result = snake.kill();

  REQUIRE(result.dead == true);
}

TEST_CASE( "moving snake")
{
  Snake snake;
  snake.positions = Positions({ {2,0}, {1,0}, {0,0} });
  snake.nextDirection = { 1, 0 };

  Snake results = snake.move();

  std::vector<Position> expected = { {3,0}, {2,0}, {1,0} };

  // Not using Position == operator so we can see diff in fail message
  REQUIRE( results.positions[0].x == expected[0].x );
  REQUIRE( results.positions[0].y == expected[0].y );

  REQUIRE( results.positions[1].x == expected[1].x );
  REQUIRE( results.positions[1].y == expected[1].y );

  REQUIRE( results.positions[2].x == expected[2].x );
  REQUIRE( results.positions[2].y == expected[2].y );


};