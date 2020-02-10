#pragma once

class Countdown
{

  public:

  float secondsLeft;
  float duration;

  Countdown(float duration);
  Countdown update(float dt);
  bool isDone();
};
