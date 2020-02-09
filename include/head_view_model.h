#pragma once

#include "view_model.h"
#include "snake.h"

struct HeadViewModel : public ViewModel
{
  HeadViewModel(Snake &snake)
  {
    int SCALE = 4.0f;
    int FRAME_SIZE = 16.0f;
    int SIZE = FRAME_SIZE * SCALE;

    origin = { FRAME_SIZE/2, FRAME_SIZE/2 };

    Position p = snake.positions[0];
    position = { (p.x * SIZE) + SIZE/2, (p.y * SIZE) + SIZE/2 };
    scale = { SCALE, SCALE };

    if(snake.dead)
      rectangle = { FRAME_SIZE * 6, 0, FRAME_SIZE, FRAME_SIZE };
    else
      rectangle = { FRAME_SIZE * 2, 0, FRAME_SIZE, FRAME_SIZE };

    Direction d = snake.currentDirection;

    if(d == RIGHT)
      rotation = {0};
    else if(d == LEFT)
      rotation = {180};
    else if(d == UP)
      rotation = {-90};
    else if(d == DOWN)
      rotation = {90};

    texture.filename =  "snake-sheet.png";
  }
};