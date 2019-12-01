#include "game.h"

Game::Game(OpenWindowInterface &openWindow, ShowMessageInterface &showMessage ) {
  this->showMessage = &showMessage;
  this->openWindow = &openWindow;
}

void Game::run() {
  this->openWindow->open();
  this->showMessage->show("Hello World");

}