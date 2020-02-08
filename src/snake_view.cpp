#include "snake_view.h"

#include "head_view_model.h"
#include "arrow_view_model.h"

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
  sf::Sprite sprite = buildSprite(HeadViewModel(snake));
  output.push_back(sprite);

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
  int SIZE = 64;
  int SCALE = 4.0f;
  int FRAME_SIZE = 16.0f;

  std::vector<sf::Sprite> results;

  for(int i = 1; i < snake.positions.size()-1; i++)
  {
    Position p = snake.positions[i];
    Position aheadPos = snake.positions[i-1];
    Position behindPos = snake.positions[i+1];

    sf::Sprite sprite;

    sprite.setTexture(texture);
    sprite.setOrigin(FRAME_SIZE/2, FRAME_SIZE/2);
    sprite.setPosition((p.x * SIZE) + SIZE/2, (p.y * SIZE) + SIZE/2);
    sprite.setScale(SCALE, SCALE);

    Direction a = { aheadPos.x - p.x, aheadPos.y - p.y };
    Direction b = { p.x - behindPos.x, p.y - behindPos.y };

    float rotation;
    sf::IntRect rect;

    if(a == b)
    {
      if(a == RIGHT)
        rotation = 0.0f;
      else if(a == LEFT)
        rotation = 180.0f;
      else if(a == UP)
        rotation = 90.0f;
      else if(a == DOWN)
        rotation = -90.0f;

      rect = sf::IntRect(FRAME_SIZE * 1, 0, FRAME_SIZE, FRAME_SIZE);
    }
    else if( (a == LEFT && b == UP)
            || (a == DOWN && b == RIGHT)
    )
    {
      rotation = 0;
      rect = sf::IntRect(FRAME_SIZE * 4, 0, FRAME_SIZE, FRAME_SIZE);
    }
    else if( (a == LEFT && b == DOWN)
            || (a == UP && b == RIGHT))
    {

      rotation = 90;
      rect = sf::IntRect(FRAME_SIZE * 4, 0, FRAME_SIZE, FRAME_SIZE);
    }
    else if( (a == RIGHT && b == DOWN)
            || (a == UP && b == LEFT))
    {

      rotation = 180;
      rect = sf::IntRect(FRAME_SIZE * 4, 0, FRAME_SIZE, FRAME_SIZE);
    }
    else if( (a == DOWN && b == LEFT)
            || (a == RIGHT && b == UP))
    {
      rotation = 270;
      rect = sf::IntRect(FRAME_SIZE * 4, 0, FRAME_SIZE, FRAME_SIZE);
    }
    else // ERROR
    {
      rotation = 0;
      rect = sf::IntRect(FRAME_SIZE * 3, 0, FRAME_SIZE, FRAME_SIZE);
    }

    sprite.setRotation(rotation);
    sprite.setTextureRect(rect);

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



