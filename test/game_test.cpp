// tests-factorial.cpp
#include "catch.hpp"

#include "game.h"

#include "show_message_mock.h"
#include "open_window_mock.h"


TEST_CASE( "Game shows message") {
  ShowMessageMock showMessage = ShowMessageMock();
  OpenWindowMock openWindow;

  Game game = Game(openWindow, showMessage);

  game.run();

  REQUIRE( showMessage.wasCalledWith("Hello World") );

}

TEST_CASE( "Game opens window") {
  ShowMessageMock showMessage;
  OpenWindowMock openWindow;

  Game game = Game(openWindow, showMessage);

  game.run();

  REQUIRE( openWindow.wasCalled );
}