#pragma once

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

// A "Gateway"
class Window
{

  public:

  sf::RenderWindow window;

  Window()
  {
    this->window.setFramerateLimit(60); // High cpu usage unless limited
  }

  void open()
  {
    this->window.create(sf::VideoMode(800, 600), "SFML works!");
  }

  void close()
  {
    this->window.close();
  }


  bool isOpen()
  {
    return this->window.isOpen();
  }

  std::vector<std::string> events()
  {
    std::vector<std::string> results;

    sf::Event event;
    while (this->window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
        results.push_back("QUIT");
        close();
      }
    }

    return results;
  }

  void clear()
  {
    this->window.clear(sf::Color::Green);
  }

  void display()
  {
    this->window.display();
  }
};