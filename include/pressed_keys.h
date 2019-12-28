#pragma once

#include <vector>
#include <SFML/Window/Keyboard.hpp>

class PressedKeys
{
  std::vector<sf::Keyboard::Key> collection;

  public:

  bool contains(sf::Keyboard::Key keyCode);
  void add(sf::Keyboard::Key keyCode);
  void remove(sf::Keyboard::Key keyCode);
  
};