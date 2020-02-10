#pragma once

#include "controls.h"
#include "next_message.h"
#include "change_direction.h"
#include "presenter.h"
#include "state.h"
#include "dialog.h"
#include <SFML/Window/Keyboard.hpp>

class GameplayControls : public Controls
{
  NextMessage nextMessage;

  ChangeDirection changeDirectionRight;
  ChangeDirection changeDirectionLeft;
  ChangeDirection changeDirectionUp;
  ChangeDirection changeDirectionDown;

  public:

  GameplayControls(Dialog &dialog, Presenter &presenter, State &state)
    : nextMessage(dialog, presenter),
    changeDirectionRight(state, {1,0}),
    changeDirectionLeft(state, {-1,0}),
    changeDirectionUp(state, {0,-1}),
    changeDirectionDown(state, {0,1})
  {
    set(sf::Keyboard::Z, nextMessage);
    set(sf::Keyboard::Right, changeDirectionRight);
    set(sf::Keyboard::Left, changeDirectionLeft);
    set(sf::Keyboard::Down, changeDirectionDown);
    set(sf::Keyboard::Up, changeDirectionUp);

  };
};