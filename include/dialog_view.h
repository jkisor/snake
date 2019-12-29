#pragma once

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

class DialogView
{

  public:

  sf::Font font;
  sf::Text text;

  DialogView();

  void setString(std::string string);
  void clear();
};