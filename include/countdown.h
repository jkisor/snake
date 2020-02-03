#pragma once

class Countdown
{

  public:

  float secondsLeft;

  Countdown(float duration);
  Countdown update(float dt);
  bool isDone();
};
