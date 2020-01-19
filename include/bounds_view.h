#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include "bounds.h"

class BoundsView
{

  public:

  sf::RectangleShape shape;

  BoundsView(Bounds &bounds);

};