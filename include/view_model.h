#pragma once

#include "position.h"
#include "origin.h"
#include "scale.h"
#include "rectangle.h"
#include "rotation.h"

struct ViewModel
{
  Position position;
  Rotation rotation;
  Scale scale;

  Origin origin;
  Rectangle rectangle;
};