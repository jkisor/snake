#include "dialog_view.h"

DialogView::DialogView()
{
  font.loadFromFile("./VCR_OSD_MONO_1.001.ttf");
  text.setFont(font);
  text.setString("");
  text.setCharacterSize(32); // in pixels, not points!
  text.setFillColor(sf::Color::White);
  // text.setStyle(sf::Text::Bold);
  text.setPosition(0, 500);
}

void DialogView::setString(std::string string)
{
  text.setString(string);
}

void DialogView::clear()
{
  text.setString("");
}