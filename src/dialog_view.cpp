#include "dialog_view.h"

DialogView::DialogView()
{
  font.loadFromFile("./basictitlefont.ttf");
  text.setFont(font);
  text.setString("");
  text.setCharacterSize(48); // in pixels, not points!
  text.setFillColor(sf::Color::Black);
  text.setStyle(sf::Text::Bold);
  text.setPosition(400, 0);
}

void DialogView::setString(std::string string)
{
  text.setString(string);
}

void DialogView::clear()
{
  text.setString("");
}