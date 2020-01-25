#include "snake_view.h"

SnakeView::SnakeView()
{
  texture.loadFromFile("snake-sheet.png");
}

std::vector<sf::Sprite> SnakeView::drawables(Snake &snake)
{
  int SIZE = 64;
  int SCALE = 4.0f;

  std::vector<sf::Sprite> output;

  // Tail
  Position tailPos = snake.positions[snake.positions.size()-1];

  sf::Sprite tailSprite;
  tailSprite.setTexture(texture);
  tailSprite.setPosition(tailPos.x * SIZE, tailPos.y * SIZE);
  tailSprite.setScale(SCALE, SCALE);
  tailSprite.setTextureRect(sf::IntRect(16 * 0, 0, 16, 16));

  output.push_back(tailSprite);

  // Body
  for(int i = 1; i < snake.positions.size()-1; i++)
  {
    Position p = snake.positions[i];

    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(p.x * SIZE, p.y * SIZE);
    sprite.setScale(SCALE, SCALE);
    sprite.setTextureRect(sf::IntRect(16 * 1, 0, 16, 16));

    output.push_back(sprite);
  }

  // Head
  Position p = snake.positions[0];

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setOrigin(16/2, 16/2); //original size
  sprite.setPosition((p.x * SIZE) + SIZE/2, (p.y * SIZE) + SIZE/2);
  sprite.setScale(SCALE, SCALE);
  sprite.setTextureRect(sf::IntRect(16 * 2, 0, 16, 16));

  float rotation;

  if(snake.direction.x == 1)
    rotation = 0.0f;
  else if(snake.direction.x == -1)
    rotation = 180.0f;
  else if(snake.direction.y == -1)
    rotation = -90.0f;
  else if(snake.direction.y == 1)
    rotation = 90.0f;

  sprite.setRotation(rotation);

  output.push_back(sprite);

  return output;

};