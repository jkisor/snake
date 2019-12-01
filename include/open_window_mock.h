#pragma once

#include "open_window_interface.h"

class OpenWindowMock : public OpenWindowInterface {

  public:
  
  bool wasCalled = false;

  void open() {
    wasCalled = true;
  }

};