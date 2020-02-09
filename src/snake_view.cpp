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
  std::vector<sf::Sprite> output;

  // Tail
  output.push_back(buildSprite(TailSprite(snake)));

  // Body
  for(int i = 1; i < snake.positions.size()-1; i++)
    output.push_back(buildSprite(BodySprite(snake, i)));

  // Head
  output.push_back(buildSprite(HeadSprite(snake)));

  // Arrow
  if(!snake.dead)
    output.push_back(buildSprite(ArrowSprite(snake)));

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



