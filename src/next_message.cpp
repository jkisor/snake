#include "next_message.h"

NextMessage::NextMessage(Dialog &d, Presenter &p)
{
  presenter = &p;
  dialog = &d;
}

void NextMessage::call()
{
  dialog->index += 1;

  if (dialog->isComplete())
    presenter->onDone();
  else
    presenter->onChangeMessage(dialog->message());
}