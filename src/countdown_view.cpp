#include "countdown_view.h"
#include <math.h> 

CountdownView::CountdownView(Countdown &countdown)
{
  texture.loadFromFile("snake-sheet.png");

  int FRAME_SIZE = 16.0f;
  int SIZE = 64;
  int SCALE = 4.0f;

  sprite.setTexture(texture);
  sprite.setOrigin(FRAME_SIZE/2, FRAME_SIZE/2);
  sprite.setPosition(800/2, 600/2); // TODO avoid hardcode
  sprite.setScale(SCALE, SCALE);

  int index = 7;

  if(ceil(countdown.secondsLeft) == 3)
    index = 7;
  else if(ceil(countdown.secondsLeft) == 2)
    index = 8;
  else if (ceil(countdown.secondsLeft) == 1)
    index = 9;
  else if (ceil(countdown.secondsLeft) == 0)
    index = 3; // TODO not apple....

  sprite.setTextureRect(sf::IntRect(FRAME_SIZE * index, 0, FRAME_SIZE, FRAME_SIZE));

}
