#include "tail_view.h"

TailView::TailView(sf::Texture &texture)
{
  this->texture = &texture;
}

sf::Sprite TailView::sprite(Snake &snake)
{
  int SIZE = 64;
  int SCALE = 4.0f;
  int FRAME_SIZE = 16.0f;

  sf::Sprite result;

  Position tailPos = snake.positions[snake.positions.size()-1];
  Position prevPos = snake.positions[snake.positions.size()-2];

  Direction direction = { prevPos.x - tailPos.x, prevPos.y - tailPos.y };

  result.setTexture(*texture);
  result.setOrigin(FRAME_SIZE/2, FRAME_SIZE/2);
  result.setPosition((tailPos.x * SIZE) + SIZE/2, (tailPos.y * SIZE) + SIZE/2);
  result.setScale(SCALE, SCALE);
  result.setTextureRect(sf::IntRect(FRAME_SIZE * 0, 0, FRAME_SIZE, FRAME_SIZE));

  int r;

  if(direction == DOWN )
    r = 90;
  else if (direction == LEFT)
    r = 180;
  else if (direction == UP)
    r = 270;
  else if (direction == RIGHT)
    r = 0;

  result.setRotation(r);

  return result;
}

