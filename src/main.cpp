#include <iostream>

#include "game.h"
#include "window.h"
#include "show_message_console.h"

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

#include "events.h"
#include "pressed_keys.h"
#include "action.h"

#include "dialog.h"
#include "dialog_view.h"
#include "presenter.h"

PressedKeys pressedKeys;

class NextMessage : public Action
{
  Presenter * presenter;
  Dialog * dialog;

  public:

  NextMessage(Dialog &d, Presenter &p)
  {
    presenter = &p;
    dialog = &d;
  }

  void call()
  {
    dialog->index += 1;

    if (dialog->isComplete())
      presenter->onDone();
    else
      presenter->onChangeMessage(dialog->message());
  }
};

std::unordered_map<sf::Keyboard::Key, Action*> actionByKey;


bool isKeyPresent(std::unordered_map<sf::Keyboard::Key, Action*> m, sf::Keyboard::Key key)
{
  return !(m.find(key) == m.end());
}

int main() {
  Dialog dialog;

  DialogView dialogView;
  dialogView.setString(dialog.message());

  Presenter presenter(dialogView);
  NextMessage nextMessage(dialog, presenter);

  actionByKey[sf::Keyboard::Key::Z] = &nextMessage;

  //
  Window window;

  window.open();

  while (window.isOpen())
  {
    Events events = window.events();

    for(sf::Event e : events.keyPresses())
    {
      if ( !pressedKeys.contains(e.key.code)) {
        pressedKeys.add(e.key.code);

        if (isKeyPresent(actionByKey, e.key.code))
          actionByKey[e.key.code]->call();

      }
    }

    for(sf::Event e : events.keyReleases())
      pressedKeys.remove(e.key.code);

    window.clear();

    window.draw(dialogView.text);

    window.display();
  }

  ShowMessageConsole showMessage;
  Game game(showMessage);
  game.run();

  return 0;
}