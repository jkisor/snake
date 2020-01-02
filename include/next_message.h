#pragma once

#include "action.h"
#include "presenter_interface.h"
#include "dialog.h"

class NextMessage : public Action
{
  PresenterInterface * presenter;
  Dialog * dialog;

  public:

  NextMessage(Dialog &d, PresenterInterface &p);
  void call();

};