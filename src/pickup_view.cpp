#include "pickup_view.h"

PickupView::PickupView(Pickup &pickup)
{
  texture.loadFromFile("snake-sheet.png");

  int FRAME_SIZE = 16.0f;
  int SIZE = 64;
  int SCALE = 4.0f;

  sprite.setTexture(texture);
  sprite.setOrigin(FRAME_SIZE/2, FRAME_SIZE/2);
  sprite.setPosition((pickup.position.x * SIZE) + SIZE/2, (pickup.position.y * SIZE) + SIZE/2);
  sprite.setScale(SCALE, SCALE);
  sprite.setTextureRect(sf::IntRect(FRAME_SIZE * 3, 0, FRAME_SIZE, FRAME_SIZE));

}
