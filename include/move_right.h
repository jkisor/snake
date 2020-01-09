#pragma once

#include "action.h"
#include "object.h"

class MoveRight : public Action
{
  Object * object;

  public:

  MoveRight(Object &object)
  {
    this->object = &object;
  }

  void call()
  {
    if( object->x < BOUNDS_WIDTH-1)
      object->x += 1;
  }

};