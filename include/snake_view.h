#pragma once

#include <vector>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "snake.h"
#include "tail_view.h"
#include "view_model.h"

class SnakeView
{
  sf::Texture texture;

  public:

  SnakeView();
  std::vector<sf::Sprite> drawables(Snake &snake);

  private:

  std::vector<sf::Sprite> bodySprites(Snake &snake);
  sf::Sprite buildSprite(ViewModel viewModel);
};