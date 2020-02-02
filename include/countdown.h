#pragma once

class Countdown
{
  float secondsLeft;

  public:

  Countdown(float duration);
  Countdown update(float dt);
  bool isDone();
};
