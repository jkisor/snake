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
    state->menuIndex += 1;
    if (state->menuIndex < )
  }
};

class MenuControls : public Controls
{

  public:

  Pick pick;
  ChangeSelectionUp up;
  ChangeSelectionDown down;

  MenuControls()
    : pick(),
    up(),
    down()
  {
    set(sf::Keyboard::Z, pick);
    set(sf::Keyboard::Up, up);
    set(sf::Keyboard::Down, down);
  };
};