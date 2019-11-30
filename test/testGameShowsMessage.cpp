// tests-factorial.cpp
#include "catch.hpp"

class ShowMessage {
  public:
  virtual void show(std::string message) = 0;
};

class TestShowMessage : public ShowMessage {
  
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

class Game {
  
  ShowMessage * showMessage;

  public:

  Game(ShowMessage &showMessage) {
    this->showMessage = &showMessage;
  }

  void run() {
    this->showMessage->show("Hello World");
  }
};

TEST_CASE( "Game shows message") {
  TestShowMessage showMessage = TestShowMessage();
  Game game = Game(showMessage);

  game.run();

  REQUIRE( showMessage.wasCalledWith("Hello World") );

}