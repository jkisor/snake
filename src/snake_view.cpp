#include "snake_view.h"

std::vector<sf::RectangleShape> SnakeView::drawables(Snake &snake)
{
  int SIZE = 64;

  std::vector<sf::RectangleShape> output;

  for(Position p : snake.positions)
  {
     sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(SIZE, SIZE));
    rectangle.setPosition(p.x * SIZE, p.y * SIZE);
    rectangle.setFillColor(sf::Color::Red);

    output.push_back(rectangle);
  }

  output[0].setFillColor(sf::Color::Green);

  return output;

};