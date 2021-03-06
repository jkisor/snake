#pragma once

#include "sprite.h"
#include "snake.h"

struct TailSprite : public Sprite
{
  TailSprite(Snake &snake)
  {
    int SIZE = 64;
    int SCALE = 4.0f;
    int FRAME_SIZE = 16.0f;

    Position tailPos = snake.positions.last();

    origin = { FRAME_SIZE/2, FRAME_SIZE/2 };
    position = { (tailPos.x * SIZE) + SIZE/2, (tailPos.y * SIZE) + SIZE/2 };
    scale = { SCALE, SCALE };
    rectangle = { FRAME_SIZE * 0, 0, FRAME_SIZE, FRAME_SIZE };

    Position prevPos = snake.positions.all[snake.positions.all.size()-2];
    Direction direction = { prevPos.x - tailPos.x, prevPos.y - tailPos.y };

    if(direction == DOWN )
      rotation = { 90 };
    else if (direction == LEFT)
      rotation = { 180 };
    else if (direction == UP)
      rotation = { 270 };
    else if (direction == RIGHT)
      rotation = { 0 };

    texture.filename =  "snake-sheet.png";

  }

};