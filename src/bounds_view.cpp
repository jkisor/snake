#include "bounds_view.h"

BoundsView::BoundsView(Bounds &bounds)
{
  texture.loadFromFile("snake-sheet.png");


  int FRAME_SIZE = 16.0f;
  int SIZE = 64;
  int SCALE = 4.0f;

  for(int y = 0; y < bounds.height; y++)
  {
    for (int x = 0; x < bounds.width; x++)
    {
      sf::Sprite s;
      s.setPosition(x * SIZE, y * SIZE);
      s.setTexture(texture);
      s.setOrigin(0, 0);

      // This cases them to change randomly every frame... need to persist the randomness
      // int arr[2] = { -1, 1 };
      // int ix = rand() % 2;
      // int iy = rand() % 2;
      // s.setScale(SCALE * arr[ix], SCALE * arr[iy]);

      s.setScale(SCALE, SCALE);
      s.setTextureRect(sf::IntRect(FRAME_SIZE * 0, FRAME_SIZE * 1, FRAME_SIZE, FRAME_SIZE));
      sprites.push_back(s);
    }

  }

  shape.setSize(sf::Vector2f(SIZE * bounds.width, SIZE * bounds.height));
  shape.setOutlineColor(sf::Color::White);
  shape.setOutlineThickness(4);
  shape.setFillColor(sf::Color(0xabcb9bff));
  shape.setPosition(0, 0);
}
