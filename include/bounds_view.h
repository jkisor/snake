#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <vector>
#include "bounds.h"

class BoundsView
{
  sf::Texture texture;

  public:

  std::vector<sf::Sprite> sprites;
  sf::RectangleShape shape;

  BoundsView(Bounds &bounds);

};