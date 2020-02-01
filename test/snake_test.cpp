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
