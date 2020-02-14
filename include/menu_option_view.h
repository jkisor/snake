#pragma once

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <string>

class MenuOptionView
{
  public:

  sf::Font font;
  sf::Text text;

  MenuOptionView(std::string string);
};