// tests-factorial.cpp
#include "catch.hpp"

#include "game.h"

#include "show_message_mock.h"

TEST_CASE( "Game shows message") {
  ShowMessageMock showMessage = ShowMessageMock();

  Game game = Game(showMessage);

  game.run();

  REQUIRE( showMessage.wasCalledWith("Hello World") );

}
