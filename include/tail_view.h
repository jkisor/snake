#pragma once

#include <vector>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "snake.h"

class TailView
{
  sf::Texture *texture;

  public:

  TailView(sf::Texture &texture);
  sf::Sprite sprite(Snake &snake);

};