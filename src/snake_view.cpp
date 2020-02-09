#include "snake_view.h"

#include "head_view_model.h"
#include "arrow_view_model.h"
#include "body_view_model.h"
#include "tail_view_model.h"


SnakeView::SnakeView()
{
  texture.loadFromFile("snake-sheet.png");
}

std::vector<sf::Sprite> SnakeView::drawables(Snake &snake)
{
  std::vector<sf::Sprite> output;

  // Tail
  output.push_back(buildSprite(TailViewModel(snake)));

  // Body
  for(int i = 1; i < snake.positions.size()-1; i++)
    output.push_back(buildSprite(BodyViewModel(snake, i)));

  // Head
  output.push_back(buildSprite(HeadViewModel(snake)));

  // Arrow
  if(!snake.dead)
    output.push_back(buildSprite(ArrowViewModel(snake)));

  return output;

};

sf::Sprite SnakeView::buildSprite(ViewModel model)
{
  sf::Sprite sprite;

  sprite.setTexture(texture);
  sprite.setOrigin(model.origin.x, model.origin.y);
  sprite.setPosition(model.position.x, model.position.y);
  sprite.setScale(model.scale.x, model.scale.y);
  sprite.setRotation(model.rotation.degrees);
  sprite.setTextureRect(sf::IntRect(model.rectangle.left, model.rectangle.top, model.rectangle.width, model.rectangle.height));

  return sprite;
}



