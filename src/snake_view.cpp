#include "snake_view.h"

std::vector<sf::RectangleShape> SnakeView::drawables(Snake &snake)
{

  int SIZE = 64;

  sf::RectangleShape rectangle;
  rectangle.setSize(sf::Vector2f(SIZE, SIZE));
  rectangle.setPosition(snake.positions[0].x * SIZE, snake.positions[0].y * SIZE);
  rectangle.setFillColor(sf::Color::Green);

  sf::RectangleShape tailRectangle;
  tailRectangle.setSize(sf::Vector2f(SIZE, SIZE));
  tailRectangle.setPosition(snake.positions[1].x * SIZE, snake.positions[1].y * SIZE);

  tailRectangle.setFillColor(sf::Color::Red);

  sf::RectangleShape otherTailRectangle;
  otherTailRectangle.setSize(sf::Vector2f(SIZE, SIZE));
  otherTailRectangle.setPosition(snake.positions[2].x * SIZE, snake.positions[2].y * SIZE);

  otherTailRectangle.setFillColor(sf::Color::Red);

  return { rectangle, tailRectangle, otherTailRectangle };
};