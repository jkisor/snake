#include "bounds_view.h"

BoundsView::BoundsView(Bounds &bounds)
{
  int SIZE = 64;

  shape.setSize(sf::Vector2f(SIZE * bounds.width, SIZE * bounds.height));
  shape.setOutlineColor(sf::Color::White);
  shape.setOutlineThickness(4);
  shape.setFillColor(sf::Color(0xabcb9bff));
  shape.setPosition(0, 0);
}
