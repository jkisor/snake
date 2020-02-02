#pragma once

#include <unordered_map>
#include <SFML/Window/Keyboard.hpp>
#include "action.h"

class Controls
{

  std::unordered_map<sf::Keyboard::Key, Action*> actionByKey;

  public:

  void set(sf::Keyboard::Key key, Action &action);

  Action * get(sf::Keyboard::Key key);
  void trigger(sf::Keyboard::Key key);

  private:

  bool isKeyPresent(sf::Keyboard::Key key);

};