#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "pickup.h"


class PickupView
{
  sf::Texture texture;

  public:

  sf::Sprite sprite;

  PickupView(Pickup &pickup);

};