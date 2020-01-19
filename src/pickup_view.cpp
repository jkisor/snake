#include "pickup_view.h"

PickupView::PickupView(Pickup &pickup)
{
  int SIZE = 64;

  shape.setSize(sf::Vector2f(SIZE, SIZE));
  shape.setFillColor(sf::Color::Yellow);
  shape.setPosition(pickup.position.x * SIZE, pickup.position.y * SIZE);

}
