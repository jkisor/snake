#pragma once

#include <vector>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "snake.h"
#include "sprite.h"

class SnakeView
{
  sf::Texture texture;

  std::vector<sf::Sprite> sprites;

  public:

  SnakeView(Snake &snake);
  std::vector<sf::Drawable *> drawables();

  private:

  sf::Sprite buildSprite(Sprite sprite);
};