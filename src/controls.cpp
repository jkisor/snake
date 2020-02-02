
#include "controls.h"

void Controls::set(sf::Keyboard::Key key, Action &action)
{
  actionByKey[key] = &action;
};

Action * Controls::get(sf::Keyboard::Key key)
{
  return actionByKey[key];
};

void Controls::trigger(sf::Keyboard::Key key)
{
  if (!isKeyPresent(key))
    return;

  get(key)->call();
};

bool Controls::isKeyPresent(sf::Keyboard::Key key)
{
  return !(actionByKey.find(key) == actionByKey.end());
}
