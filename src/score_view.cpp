#include "score_view.h"
#include <string>

ScoreView::ScoreView(int score)
{
  font.loadFromFile("./VCR_OSD_MONO_1.001.ttf");
  text.setFont(font);
  text.setString(std::to_string(score));
  text.setCharacterSize(64); // in pixels, not points!
  text.setFillColor(sf::Color::White);
  // text.setStyle(sf::Text::Bold);
  text.setPosition(0, 500);
}
