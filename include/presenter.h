#pragma once

#include "presenter_interface.h"
#include "dialog_view.h"

class Presenter : public PresenterInterface
{
  DialogView * view;

  public:

  Presenter(DialogView &v);

  virtual void onChangeMessage(std::string message);
  virtual void onDone();
};