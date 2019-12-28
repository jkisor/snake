#include "pressed_keys.h"

bool PressedKeys::contains(sf::Keyboard::Key keyCode)
{
  return std::find(collection.begin(), collection.end(), keyCode) != collection.end();
};

void PressedKeys::add(sf::Keyboard::Key keyCode) {
  collection.push_back(keyCode);
};

void PressedKeys::remove(sf::Keyboard::Key keyCode)
{
  collection.erase(
    std::remove(collection.begin(), collection.end(), keyCode),
    collection.end()
  );

};
