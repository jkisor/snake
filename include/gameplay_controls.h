#pragma once

#include "controls.h"
#include "change_direction.h"
#include "state.h"
#include <SFML/Window/Keyboard.hpp>

class GameplayControls : public Controls
{
  ChangeDirection changeDirectionRight;
  ChangeDirection changeDirectionLeft;
  ChangeDirection changeDirectionUp;
  ChangeDirection changeDirectionDown;

  public:

  GameplayControls(State &state)
    : changeDirectionRight(state, {1,0}),
    changeDirectionLeft(state, {-1,0}),
    changeDirectionUp(state, {0,-1}),
    changeDirectionDown(state, {0,1})
  {
    set(sf::Keyboard::Right, changeDirectionRight);
    set(sf::Keyboard::Left, changeDirectionLeft);
    set(sf::Keyboard::Down, changeDirectionDown);
    set(sf::Keyboard::Up, changeDirectionUp);

  };
};