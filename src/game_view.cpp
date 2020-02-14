#include "game_view.h"

GameView::GameView(State &state) :
  bounds_view(state.bounds),
  pickup_view(state.pickup),
  snakeView(state.snake)
{
  this->state = &state;
}

std::vector<sf::Drawable *> GameView::drawables()
{
  std::vector<sf::Drawable *> results;

  results.push_back(&bounds_view.shape);


  for(sf::Drawable * d : snakeView.drawables())
    results.push_back(d);

  results.push_back(&pickup_view.sprite);

  return results;
}
