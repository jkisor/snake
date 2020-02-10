#pragma once

#include "snake.h"
#include "pickup.h"
#include "bounds.h"

class Menu
{

  public:

  int index = 0;
  int numOptions = 1;

  Menu up()
  {
    Menu result(*this);

    int newIndex = index - 1;

    if(newIndex >= 0)
      result.index = newIndex;

    return result;

  }

  Menu down()
  {
    Menu result(*this);

    int newIndex = index + 1;

    if(newIndex < numOptions)
      result.index = newIndex;

    return result;

  }
};

struct State
{
  Snake snake;
  Pickup pickup;
  Bounds bounds;

  int menuIndex;
};