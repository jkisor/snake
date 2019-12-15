#include "game.h"

Game::Game(ShowMessageInterface &showMessage ) {
  this->showMessage = &showMessage;
}

void Game::run() {
  this->showMessage->show("Hello World");

}