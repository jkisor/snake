#pragma once

#include "action.h"
#include "object.h"

class MoveDown : public Action
{
  Object * object;

  public:

  MoveDown(Object &object)
  {
    this->object = &object;
  }

  void call()
  {
    if( object->y < BOUNDS_HEIGHT-1 && (object->y + 1) != object->tailY )
    {
      object->tailX = object->x;
      object->tailY = object->y;

      object->y += 1;
    }

  }

};