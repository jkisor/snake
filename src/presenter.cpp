#include "presenter.h"

Presenter::Presenter(DialogView &v)
{
  view = &v;
}

void Presenter::onChangeMessage(std::string message)
{
  view->setString(message);
}

void Presenter::onDone()
{
  view->clear();
}