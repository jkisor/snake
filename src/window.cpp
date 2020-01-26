#include "window.h"

void Window::open()
{
  this->window.create(sf::VideoMode(800, 600), "SFML works!");

  // High cpu usage unless limited
  // MUST be called after create.
  this->window.setFramerateLimit(60);
}

void Window::close()
{
  this->window.close();
}

bool Window::isOpen()
{
  return this->window.isOpen();
}

Events Window::events()
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

void Window::clear()
{
  this->window.clear(sf::Color::Black);
}

void Window::display()
{
  this->window.display();
}

void Window::draw(const sf::Drawable &drawable){
  this->window.draw(drawable);
}