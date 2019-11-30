#include "game.h"

Game::Game(ShowMessage &showMessage) {
  this->showMessage = &showMessage;
}

void Game::run() {
  this->showMessage->show("Hello World");
}