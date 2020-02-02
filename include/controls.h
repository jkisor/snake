#pragma once

#include <unordered_map>
#include <SFML/Window/Keyboard.hpp>
#include "action.h"

class Controls
{

  public:

  std::unordered_map<sf::Keyboard::Key, Action*> actionByKey;

  void set(sf::Keyboard::Key key, Action &action)
  {
    actionByKey[key] = &action;
  };

  Action * get(sf::Keyboard::Key key)
  {
    return actionByKey[key];
  };

  void trigger(sf::Keyboard::Key key)
  {
    if (!isKeyPresent(key))
      return;

    get(key)->call();
  };

  private:

  bool isKeyPresent(sf::Keyboard::Key key)
  {
    return !(actionByKey.find(key) == actionByKey.end());
  }

};