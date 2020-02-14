#pragma once

#include <SFML/Graphics.hpp>

#include "menu_option_view.h"
#include "state.h"

class MenuView
{
  public:

  MenuView(State &state);

  sf::RectangleShape shape;
  MenuOptionView option1;
  MenuOptionView option2;
  sf::RectangleShape cursorShape;

};