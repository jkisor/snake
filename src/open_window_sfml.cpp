#include "open_window_sfml.h"
#include <SFML/Graphics.hpp>

void OpenWindowSFML::open() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
  window.setFramerateLimit(60); // High cpu usage unless limited

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed)
            window.close();
    }

    window.clear(sf::Color::Black);
    window.display();
  }
}