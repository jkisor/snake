#pragma once

#include "view_model.h"

struct BodyViewModel : public ViewModel
{
  BodyViewModel(Snake &snake, int index)
  {
    int SIZE = 64;
    int SCALE = 4.0f;
    int FRAME_SIZE = 16.0f;

    Position p = snake.positions[index];
    Position aheadPos = snake.positions[index-1];
    Position behindPos = snake.positions[index+1];

    origin = { FRAME_SIZE/2, FRAME_SIZE/2 };
    position = { (p.x * SIZE) + SIZE/2, (p.y * SIZE) + SIZE/2 };
    scale = { SCALE, SCALE };

    Direction a = { aheadPos.x - p.x, aheadPos.y - p.y };
    Direction b = { p.x - behindPos.x, p.y - behindPos.y };

    if(a == b)
    {
      if(a == RIGHT)
        rotation = { 0 };
      else if(a == LEFT)
        rotation = { 180 };
      else if(a == UP)
        rotation = { 90 };
      else if(a == DOWN)
        rotation = {-90};

      rectangle = { FRAME_SIZE * 1, 0, FRAME_SIZE, FRAME_SIZE };
    }
    else if( (a == LEFT && b == UP)
            || (a == DOWN && b == RIGHT)
    )
    {
      rotation = {0};
      rectangle = { FRAME_SIZE * 4, 0, FRAME_SIZE, FRAME_SIZE };
    }
    else if( (a == LEFT && b == DOWN)
            || (a == UP && b == RIGHT))
    {

      rotation = {90};
      rectangle = { FRAME_SIZE * 4, 0, FRAME_SIZE, FRAME_SIZE};
    }
    else if( (a == RIGHT && b == DOWN)
            || (a == UP && b == LEFT))
    {

      rotation = {180};
      rectangle = { FRAME_SIZE * 4, 0, FRAME_SIZE, FRAME_SIZE };
    }
    else if( (a == DOWN && b == LEFT)
            || (a == RIGHT && b == UP))
    {
      rotation = {270};
      rectangle = { FRAME_SIZE * 4, 0, FRAME_SIZE, FRAME_SIZE };
    }
    else // ERROR
    {
      rotation = {0};
      rectangle = { FRAME_SIZE * 3, 0, FRAME_SIZE, FRAME_SIZE };
    }

    texture.filename =  "snake-sheet.png";

  }
};