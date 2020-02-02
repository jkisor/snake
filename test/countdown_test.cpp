#include "catch.hpp"
#include "countdown.h"

TEST_CASE("countdown from zero is already done")
{
  Countdown countdown(0.0f);

  REQUIRE(countdown.isDone());
}

TEST_CASE("countdown with timeleft is not done")
{
  Countdown countdown(666.0f);

  REQUIRE(!countdown.isDone());
}

TEST_CASE("updated full duration")
{
  float duration = 1.0f;
  Countdown countdown(duration);
  float dt = duration;

  Countdown result = countdown.update(dt);

  REQUIRE(result.isDone());
}

TEST_CASE("updated less than duration")
{
  float duration = 1.0f;
  Countdown countdown(duration);
  float dt = duration / 2;

  Countdown result = countdown.update(dt);

  REQUIRE(!result.isDone());
}

TEST_CASE("updated more than duration")
{
  float duration = 1.0f;
  Countdown countdown(duration);
  float dt = duration * 2;

  Countdown result = countdown.update(dt);

  REQUIRE(result.isDone());
}