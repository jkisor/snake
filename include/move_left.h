#pragma once

#include "action.h"

#include "object.h"

class MoveLeft : public Action
{
  Object * object;

  public:

  MoveLeft(Object &object)
  {
    this->object = &object;
  }

  void call()
  {
    if( object->x > 0 )
      object->x -= 1;
  }
};