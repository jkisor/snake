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

TEST_CASE("Adding to snake")
{
  Position p = {0,0};
  Snake snake;

  Snake result = snake.add({0,0});

  REQUIRE(result.tail() == p);
}

TEST_CASE("killing snake")
{
  Snake snake;

  Snake result = snake.kill();

  REQUIRE(result.dead == true);
}