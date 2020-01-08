#pragma once

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "events.h"

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

  Events events()
  {
    std::vector<sf::Event> results;

    sf::Event event;
    while (this->window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        close();
      
      results.push_back(event);
    }

    return Events(results);
  }

  void clear()
  {
    this->window.clear(sf::Color::Black);
  }

  void display()
  {
    this->window.display();
  }

  void draw(const sf::Drawable &drawable){
    this->window.draw(drawable);
  }
};