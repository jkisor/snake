#include "menu_view.h"


MenuView::MenuView(State &state) :
  option1("Play"),
  option2("Quit")
{

  shape.setPosition(0, 0);
  shape.setSize(sf::Vector2f(800, 600));
  shape.setFillColor(sf::Color(255,0,0,255));

  option1.text.setPosition(100, 100);
  option2.text.setPosition(100, 164);

  if(state.menuIndex == 0)
    cursorShape.setPosition(72, 100 + 8);
  else if(state.menuIndex == 1)
    cursorShape.setPosition(72, 164 + 8);

  cursorShape.setSize(sf::Vector2f(16, 16));
  cursorShape.setFillColor(sf::Color(255,255,255,255));


}

std::vector<sf::Drawable *> MenuView::drawables()
{
  std::vector<sf::Drawable *> results;

  results.push_back(&shape);
  results.push_back(&option1.text);
  results.push_back(&option2.text);
  results.push_back(&cursorShape);
  return results;

};