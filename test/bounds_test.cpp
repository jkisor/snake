#include "catch.hpp"

#include "bounds.h"

TEST_CASE( "bounds", "contains points")
{
  Bounds bounds;

  bounds.width = 10;
  bounds.height = 10;

  Position inside = {0,0};
  Position outside = {666,666};


  REQUIRE(bounds.contains(inside));
  REQUIRE(!bounds.contains(outside));


};