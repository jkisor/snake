#pragma once

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

class ScoreView
{

  public:

  sf::Font font;
  sf::Text text;

  ScoreView(int score);

};