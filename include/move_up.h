#pragma once

#include "action.h"
#include "object.h"

class MoveUp : public Action
{
  Object * object;

  public:

  MoveUp(Object &object)
  {
    this->object = &object;
  }

  void call()
  {
    if( object->y > 0 )
    {
      object->tailX = object->x;
      object->tailY = object->y;
      object->y -= 1;
    }

  }
};
