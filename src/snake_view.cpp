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
  Direction tailDir = snake.directions[snake.directions.size()-1];


  sf::Sprite tailSprite;
  tailSprite.setTexture(texture);
  tailSprite.setOrigin(FRAME_SIZE/2, FRAME_SIZE/2);
  tailSprite.setPosition((tailPos.x * SIZE) + SIZE/2, (tailPos.y * SIZE) + SIZE/2);
  tailSprite.setScale(SCALE, SCALE);
  tailSprite.setTextureRect(sf::IntRect(FRAME_SIZE * 0, 0, FRAME_SIZE, FRAME_SIZE));

  float tailRotation;

    if(tailDir.x == 1)
      tailRotation = 0.0f;
    else if(tailDir.x == -1)
      tailRotation = 180.0f;
    else if(tailDir.y == -1)
      tailRotation = -90.0f;
    else if(tailDir.y == 1)
      tailRotation = 90.0f;

    tailSprite.setRotation(tailRotation);


  output.push_back(tailSprite);

  // Body
  for(int i = 1; i < snake.positions.size()-1; i++)
  {
    Position p = snake.positions[i];
    Position prevPos = snake.positions[i-1];
    Position nextPos = snake.positions[i+1];

    Direction d = snake.directions[i];

    sf::Sprite sprite;

    sprite.setTexture(texture);
    sprite.setOrigin(FRAME_SIZE/2, FRAME_SIZE/2);
    sprite.setPosition((p.x * SIZE) + SIZE/2, (p.y * SIZE) + SIZE/2);
    sprite.setScale(SCALE, SCALE);

    Direction dd = { prevPos.x - nextPos.x, prevPos.y - nextPos.y };
    if(dd.x == 1 && dd.y == 1 )
    {
      float rotation = 0;
      sprite.setRotation(rotation);
      sprite.setTextureRect(sf::IntRect(FRAME_SIZE * 4, 0, FRAME_SIZE, FRAME_SIZE));
    }

    else if (dd.x == 1 && dd.y == -1)
    {
      float rotation = 270.0f;
      sprite.setRotation(rotation);
      sprite.setTextureRect(sf::IntRect(FRAME_SIZE * 4, 0, FRAME_SIZE, FRAME_SIZE));
    }

    else if (dd.x == -1 && dd.y == -1)
    {
      float rotation = 180.0f;
      sprite.setRotation(rotation);
      sprite.setTextureRect(sf::IntRect(FRAME_SIZE * 4, 0, FRAME_SIZE, FRAME_SIZE));
    }

    else if (dd.x == -1 && dd.y == 1)
    {
      float rotation = 90.0f;

      sprite.setRotation(rotation);
      sprite.setTextureRect(sf::IntRect(FRAME_SIZE * 4, 0, FRAME_SIZE, FRAME_SIZE));
    }

    else
    {
      float rotation;

      if(d.x == 1)
        rotation = 0.0f;
      else if(d.x == -1)
        rotation = 180.0f;
      else if(d.y == -1)
        rotation = 90.0f;
      else if(d.y == 1)
        rotation = -90.0f;

      sprite.setRotation(rotation);
      sprite.setTextureRect(sf::IntRect(FRAME_SIZE * 1, 0, FRAME_SIZE, FRAME_SIZE));
    }

    output.push_back(sprite);
  }

  // Head
  Position p = snake.positions[0];
  Direction d = snake.directions[0];

  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setOrigin(FRAME_SIZE/2, FRAME_SIZE/2);
  sprite.setPosition((p.x * SIZE) + SIZE/2, (p.y * SIZE) + SIZE/2);
  sprite.setScale(SCALE, SCALE);
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

  return output;

};