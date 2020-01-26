#pragma once

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "events.h"

class Window
{

  public:

  sf::RenderWindow window;

  void open();
  void close();
  bool isOpen();
  Events events();
  void clear();
  void display();
  void draw(const sf::Drawable &drawable);
};