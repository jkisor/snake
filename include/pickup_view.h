#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include "pickup.h"

class PickupView
{

  public:

  sf::RectangleShape shape;

  PickupView(Pickup &pickup);

};