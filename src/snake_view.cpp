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
  Position tailPos = snake.positions[snake.positions.size()-1];
  Position prevPos = snake.positions[snake.positions.size()-2];

  Direction tailDir = { prevPos.x - tailPos.x, prevPos.y - tailPos.y };

  sf::Sprite tailSprite;
  tailSprite.setTexture(texture);
  tailSprite.setOrigin(FRAME_SIZE/2, FRAME_SIZE/2);
  tailSprite.setPosition((tailPos.x * SIZE) + SIZE/2, (tailPos.y * SIZE) + SIZE/2);
  tailSprite.setScale(SCALE, SCALE);
  tailSprite.setTextureRect(sf::IntRect(FRAME_SIZE * 0, 0, FRAME_SIZE, FRAME_SIZE));

  if(tailDir.x == 0 && tailDir.y == 1 )
    tailSprite.setRotation(90);
  else if (tailDir.x == -1 && tailDir.y == 0)
    tailSprite.setRotation(180);
  else if (tailDir.x == 0 && tailDir.y == -1)
    tailSprite.setRotation(270);
  else if (tailDir.x == 1 && tailDir.y == 0)
    tailSprite.setRotation(0);

  output.push_back(tailSprite);

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
    if(a == b)
    {
      float rotation;

      if(a.x == 1)
        rotation = 0.0f;
      else if(a.x == -1)
        rotation = 180.0f;
      else if(a.y == -1)
        rotation = 90.0f;
      else if(a.y == 1)
        rotation = -90.0f;

      sprite.setRotation(rotation);
      sprite.setTextureRect(sf::IntRect(FRAME_SIZE * 1, 0, FRAME_SIZE, FRAME_SIZE));
    }
    else if( (a == LEFT && b == UP)
            || (a == DOWN && b == RIGHT)
    )
    {
      sprite.setRotation(0);
      sprite.setTextureRect(sf::IntRect(FRAME_SIZE * 4, 0, FRAME_SIZE, FRAME_SIZE));
    }
    else if( (a == LEFT && b == DOWN)
            || (a == UP && b == RIGHT))
    {
      sprite.setRotation(90);
      sprite.setTextureRect(sf::IntRect(FRAME_SIZE * 4, 0, FRAME_SIZE, FRAME_SIZE));
    }
    else if( (a == RIGHT && b == DOWN)
            || (a == UP && b == LEFT))
    {
      sprite.setRotation(180);
      sprite.setTextureRect(sf::IntRect(FRAME_SIZE * 4, 0, FRAME_SIZE, FRAME_SIZE));
    }
    else if( (a == DOWN && b == LEFT)
            || (a == RIGHT && b == UP))
    {
      sprite.setRotation(270);
      sprite.setTextureRect(sf::IntRect(FRAME_SIZE * 4, 0, FRAME_SIZE, FRAME_SIZE));
    }
    else // ERROR
    {
      sprite.setTextureRect(sf::IntRect(FRAME_SIZE * 3, 0, FRAME_SIZE, FRAME_SIZE));
    }

    output.push_back(sprite);
  }

  // Head
  Position p = snake.positions[0];
  Direction d = snake.currentDirection;

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setOrigin(FRAME_SIZE/2, FRAME_SIZE/2);
  sprite.setPosition((p.x * SIZE) + SIZE/2, (p.y * SIZE) + SIZE/2);
  sprite.setScale(SCALE, SCALE);

  if(snake.dead)
    sprite.setTextureRect(sf::IntRect(FRAME_SIZE * 6, 0, FRAME_SIZE, FRAME_SIZE));
  else
    sprite.setTextureRect(sf::IntRect(FRAME_SIZE * 2, 0, FRAME_SIZE, FRAME_SIZE));

  float rotation;

  if(d.x == 1)
    rotation = 0.0f;
  else if(d.x == -1)
    rotation = 180.0f;
  else if(d.y == -1)
    rotation = -90.0f;
  else if(d.y == 1)
    rotation = 90.0f;

  sprite.setRotation(rotation);
  output.push_back(sprite);

  if(!snake.dead)
  {

    sf::Sprite arrowSprite;

    arrowSprite.setTexture(texture);
    arrowSprite.setOrigin(FRAME_SIZE/2, FRAME_SIZE/2);
    arrowSprite.setPosition(((p.x + snake.nextDirection.x ) * SIZE) + SIZE/2, ((p.y + snake.nextDirection.y ) * SIZE) + SIZE/2);
    arrowSprite.setScale(SCALE, SCALE);
    arrowSprite.setTextureRect(sf::IntRect(FRAME_SIZE * 5, 0, FRAME_SIZE, FRAME_SIZE));

    arrowSprite.setRotation(arrowRotation(snake.nextDirection));
    output.push_back(arrowSprite);

  }

  return output;

};

int SnakeView::arrowRotation(Direction direction)
{
  int result;

  if(direction.x == 1)
    result = 0;
  else if(direction.x == -1)
    result = 180;
  else if(direction.y == -1)
    result = -90;
  else if(direction.y == 1)
    result = 90;

  return result;
}
