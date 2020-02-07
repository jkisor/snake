#include "snake_view.h"

SnakeView::SnakeView()
{
  texture.loadFromFile("snake-sheet.png");
}

std::vector<sf::Sprite> SnakeView::drawables(Snake &snake)
{
  int SIZE = 64;
  int SCALE = 4.0f;
  int FRAME_SIZE = 16.0f;

  std::vector<sf::Sprite> output;

  // Tail
  TailView tailView(texture);
  output.push_back(tailView.sprite(snake));

  // Body
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

    output.push_back(sprite);
  }

  // Head
  sf::Sprite sprite = headSprite(snake);
  output.push_back(sprite);

  // Arrow
  if(!snake.dead)
  {
    sf::Sprite arrow_sprite = arrowSprite(snake);
    output.push_back(arrow_sprite);
  }

  return output;

};

int SnakeView::arrowRotation(Direction direction)
{
  int result;

  if(direction == RIGHT)
    result = 0;
  else if(direction == LEFT)
    result = 180;
  else if(direction == UP)
    result = -90;
  else if(direction == DOWN)
    result = 90;

  return result;
}

sf::Sprite SnakeView::headSprite(Snake &snake)
{
  int SIZE = 64;
  int SCALE = 4.0f;
  int FRAME_SIZE = 16.0f;

  Position p = snake.positions[0];
  Direction d = snake.currentDirection;

  sf::Sprite sprite;

  sprite.setTexture(texture);
  sprite.setOrigin(FRAME_SIZE/2, FRAME_SIZE/2);
  sprite.setPosition((p.x * SIZE) + SIZE/2, (p.y * SIZE) + SIZE/2);
  sprite.setScale(SCALE, SCALE);

  sf::IntRect rect;

  if(snake.dead)
    rect = sf::IntRect(FRAME_SIZE * 6, 0, FRAME_SIZE, FRAME_SIZE);
  else
    rect = sf::IntRect(FRAME_SIZE * 2, 0, FRAME_SIZE, FRAME_SIZE);

  float rotation;

  if(d == RIGHT)
    rotation = 0;
  else if(d == LEFT)
    rotation = 180;
  else if(d == UP)
    rotation = -90;
  else if(d == DOWN)
    rotation = 90;


  sprite.setRotation(rotation);
  sprite.setTextureRect(rect);

  return sprite;
}

sf::Sprite SnakeView::arrowSprite(Snake &snake)
{
  int SIZE = 64;
  int SCALE = 4.0f;
  int FRAME_SIZE = 16.0f;

  Position p = snake.positions[0];

  sf::Sprite sprite;

  sprite.setTexture(texture);
  sprite.setOrigin(FRAME_SIZE/2, FRAME_SIZE/2);
  sprite.setPosition(((p.x + snake.nextDirection.x ) * SIZE) + SIZE/2, ((p.y + snake.nextDirection.y ) * SIZE) + SIZE/2);
  sprite.setScale(SCALE, SCALE);
  sprite.setTextureRect(sf::IntRect(FRAME_SIZE * 5, 0, FRAME_SIZE, FRAME_SIZE));

  sprite.setRotation(arrowRotation(snake.nextDirection));

  return sprite;

}

