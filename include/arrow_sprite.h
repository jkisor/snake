#pragma once

#include "sprite.h"
#include "snake.h"

struct ArrowSprite : public Sprite
{
  ArrowSprite(Snake &snake)
  {
    int SIZE = 64;
    int SCALE = 4.0f;
    int FRAME_SIZE = 16.0f;

    Position p = snake.positions.first();

    origin = { FRAME_SIZE/2, FRAME_SIZE/2 };
    position = { ((p.x + snake.nextDirection.x ) * SIZE) + SIZE/2, ((p.y + snake.nextDirection.y ) * SIZE) + SIZE/2 };
    scale = { SCALE, SCALE };

    rectangle = { FRAME_SIZE * 5, 0, FRAME_SIZE, FRAME_SIZE };

    Direction direction = snake.nextDirection;

    if(direction == RIGHT)
      rotation = {0};
    else if(direction == LEFT)
      rotation = {180};
    else if(direction == UP)
      rotation = {-90};
    else if(direction == DOWN)
      rotation = {90};

    texture.filename =  "snake-sheet.png";
  }
};