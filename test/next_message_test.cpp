// tests-factorial.cpp
#include "catch.hpp"
#include "next_message.h"

class PresenterMock : public PresenterInterface
{
  public:

  bool onChangeMessageCalled = false;
  bool onDoneCalled = false;

  virtual void onChangeMessage(std::string message);
  virtual void onDone();
};

void PresenterMock::onChangeMessage(std::string message)
{
  onChangeMessageCalled = true;
};

void PresenterMock::onDone()
{
  onDoneCalled = true;
};


TEST_CASE( "Next Message when dialog has messages", "presents the change") {
  Dialog dialog;
  PresenterMock presenter;

  NextMessage nextMessage = NextMessage(dialog, presenter);

  nextMessage.call();

  REQUIRE( presenter.onChangeMessageCalled == true );
}

TEST_CASE("Next Message when dialog has no messages left", "presents dialog is done") {
  Dialog dialog;
  dialog.messages.clear();

  PresenterMock presenter;

  NextMessage nextMessage = NextMessage(dialog, presenter);

  nextMessage.call();

  REQUIRE( presenter.onDoneCalled == true );
}
