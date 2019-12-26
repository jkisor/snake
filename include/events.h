#pragma once

#include <vector>
#include <SFML/Window/Event.hpp>

class Events
{
  public:

  std::vector<sf::Event> all;

  Events(std::vector<sf::Event> events);

  std::vector<sf::Event> keyPresses();
  std::vector<sf::Event> keyReleases();

};