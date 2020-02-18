#pragma once

#include <vector>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Events
{
  public:

  std::vector<sf::Event> all;

  Events(sf::RenderWindow &window);

  std::vector<sf::Event> keyPresses();
  std::vector<sf::Event> keyReleases();

};