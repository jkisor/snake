#include "events.h"

Events::Events(sf::RenderWindow &window)
{
  sf::Event event;

  while (window.pollEvent(event))
  {
    if (event.type == sf::Event::Closed)
      window.close();

    all.push_back(event);
  }

}

std::vector<sf::Event> Events::keyPresses()
{
  std::vector<sf::Event> results;

  for(auto e : all)
  {
    if (e.type == sf::Event::KeyPressed)
      results.push_back(e);
  }

  return results;
}

std::vector<sf::Event> Events::keyReleases()
{
  std::vector<sf::Event> results;

  for(auto e : all)
  {
    if (e.type == sf::Event::KeyReleased)
      results.push_back(e);
  }

  return results;
}
