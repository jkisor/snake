#pragma once

#include <string>
#include "dialog_view.h"

class Presenter
{
  DialogView * view;

  public:

  Presenter(DialogView &v);

  void onChangeMessage(std::string message);
  void onDone();
};