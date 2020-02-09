#include "snake_view.h"

#include "head_view_model.h"
#include "arrow_view_model.h"
#include "body_view_model.h"

SnakeView::SnakeView()
{
  texture.loadFromFile("snake-sheet.png");
}

std::vector<sf::Sprite> SnakeView::drawables(Snake &snake)
{
  std::vector<sf::Sprite> output;

  // Tail
  TailView tailView(texture);
  output.push_back(tailView.sprite(snake));

  // Body
  std::vector<sf::Sprite> body_sprites = bodySprites(snake);
  output.insert(output.end(), body_sprites.begin(), body_sprites.end() );

  // Head
  output.push_back(buildSprite(HeadViewModel(snake)));

  // Arrow
  if(!snake.dead)
  {
    sf::Sprite arrow_sprite = buildSprite(ArrowViewModel(snake));
    output.push_back(arrow_sprite);
  }

  return output;

};

std::vector<sf::Sprite> SnakeView::bodySprites(Snake &snake)
{
  std::vector<sf::Sprite> results;

  for(int i = 1; i < snake.positions.size()-1; i++)
  {
    sf::Sprite sprite = buildSprite(BodyViewModel(snake, i));
    results.push_back(sprite);
  }

  return results;
}

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



