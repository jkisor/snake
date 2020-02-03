#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "countdown.h"

class CountdownView
{
  sf::Texture texture;

  public:

  sf::Sprite sprite;

  CountdownView(Countdown &countdown);

};