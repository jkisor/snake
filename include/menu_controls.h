#pragma once

#include "action.h"
#include "controls.h"

#include "state.h"

class Pick : public Action
{
  State * state;

  public:

  Pick(State &state)
  {
    this->state = &state;
  }

  void call()
  {
    if(state->menuIndex == 0)
    {
      state->isOnMainMenu = false;
    }
    else if(state->menuIndex == 1)
    {
      state->quit = true;
    }
  }
};

class ChangeSelectionUp : public Action
{
  State * state;

  public:

  ChangeSelectionUp(State &state)
  {
    this->state = &state;
  }


  void call()
  {
    int index = state->menuIndex - 1;

    if(index >= 0 )
      state->menuIndex = index;
  }
};

class ChangeSelectionDown: public Action
{
  State * state;

  public:

  ChangeSelectionDown(State &state)
  {
    this->state = &state;
  }

  void call()
  {
    int index = state->menuIndex + 1;

    if(index < 2)
      state->menuIndex = index;
  }
};

class MenuControls : public Controls
{

  public:

  Pick pick;
  ChangeSelectionUp up;
  ChangeSelectionDown down;

  MenuControls(State &state)
    : pick(state),
    up(state),
    down(state)
  {
    set(sf::Keyboard::Enter, pick);
    set(sf::Keyboard::Up, up);
    set(sf::Keyboard::Down, down);
  };
};