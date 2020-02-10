#include "countdown.h"

Countdown::Countdown(float duration)
{
  this->duration = duration;
  secondsLeft = duration;
}

Countdown Countdown::update(float dt)
{
  Countdown result(*this);

  result.secondsLeft = secondsLeft - dt;

  return result;
}

bool Countdown::isDone()
{
  return secondsLeft <= 0.0f;
}