#include "snake_view.h"

#include "head_sprite.h"
#include "arrow_sprite.h"
#include "body_sprite.h"
#include "tail_sprite.h"


SnakeView::SnakeView()
{
  texture.loadFromFile("snake-sheet.png");
}

std::vector<sf::Sprite> SnakeView::drawables(Snake &snake)
{
  std::vector<Sprite> sprites;

  // Tail
  sprites.push_back(TailSprite(snake));

  // Body
  for(int i = 1; i < snake.positions.size()-1; i++)
    sprites.push_back(BodySprite(snake, i));

  // Head
  sprites.push_back(HeadSprite(snake));

  // Arrow
  if(!snake.dead)
    sprites.push_back(ArrowSprite(snake));

  std::vector<sf::Sprite> output;

  for(Sprite s : sprites)
    output.push_back(buildSprite(s));

  return output;

};

sf::Sprite SnakeView::buildSprite(Sprite sprite)
{
  sf::Sprite result;

  result.setTexture(texture);
  result.setOrigin(sprite.origin.x, sprite.origin.y);
  result.setPosition(sprite.position.x, sprite.position.y);
  result.setScale(sprite.scale.x, sprite.scale.y);
  result.setRotation(sprite.rotation.degrees);
  result.setTextureRect(sf::IntRect(sprite.rectangle.left, sprite.rectangle.top, sprite.rectangle.width, sprite.rectangle.height));

  return result;
}



