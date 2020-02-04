#pragma once

#include <vector>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "snake.h"

class SnakeView
{
  sf::Texture texture;

  public:

  SnakeView();
  std::vector<sf::Sprite> drawables(Snake &snake);

  private:

  int arrowRotation(Direction direction);
  sf::Sprite buildTailSprite(Snake &snake);
};