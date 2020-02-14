#include "menu_option_view.h"

MenuOptionView::MenuOptionView(std::string string)
{
  font.loadFromFile("./VCR_OSD_MONO_1.001.ttf");
  text.setFont(font);
  text.setString(string);
  text.setCharacterSize(32); // in pixels, not points!
  text.setFillColor(sf::Color::White);
  // text.setStyle(sf::Text::Bold);
  text.setPosition(0, 500);
}