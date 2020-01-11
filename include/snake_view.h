#pragma once

#include <vector>
#include <SFML/Graphics/RectangleShape.hpp>

#include "snake.h"

class SnakeView
{
  public:

  std::vector<sf::RectangleShape> drawables(Snake &snake);

};