#pragma once

#include "action.h"
#include "presenter.h"
#include "dialog.h"

class NextMessage : public Action
{
  Presenter * presenter;
  Dialog * dialog;

  public:

  NextMessage(Dialog &d, Presenter &p);
  void call();

};