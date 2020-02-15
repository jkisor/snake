#include "positions.h"
#include <algorithm>

Positions::Positions()
{
}

Positions::Positions(std::vector<Position> collection)
{
  all = collection;
}

Positions Positions::except(Positions blacklist)
{
  Positions results;

  std::copy_if(
    all.begin(),
    all.end(),
    std::back_inserter(results.all),
    [blacklist](Position p) { return std::find(blacklist.all.begin(), blacklist.all.end(), p) == blacklist.all.end(); } // not found
  );

  return results;
}