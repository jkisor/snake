#pragma once

#include <vector>
#include "position.h"

class Positions
{
  public:

  std::vector<Position> all;

  Positions();

  Positions(std::vector<Position> collection);

  Positions except(Positions blacklist);

};