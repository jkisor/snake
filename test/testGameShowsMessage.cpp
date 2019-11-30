// tests-factorial.cpp
#include "catch.hpp"

#include "game.h"

class MockShowMessage : public ShowMessage {
  
  public:

  bool wasCalled = false;
  std::string argument;

  void show(std::string message) {
    wasCalled = true;
    argument = message;
  }

  bool wasCalledWith(std::string argument) {
    return ( wasCalled && this->argument == argument );
  }

};

TEST_CASE( "Game shows message") {
  MockShowMessage showMessage = MockShowMessage();
  Game game = Game(showMessage);

  game.run();

  REQUIRE( showMessage.wasCalledWith("Hello World") );

}