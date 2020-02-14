#pragma once

#include <SFML/Graphics.hpp>
#include "menu_option_view.h"
#include "state.h"
#include <vector>

class MenuView
{
  public:

  sf::RectangleShape shape;
  MenuOptionView option1;
  MenuOptionView option2;
  sf::RectangleShape cursorShape;

  MenuView(State &state);
  std::vector<sf::Drawable *> drawables();

};