//
// Init.cpp for init in /home/charle_b//Desktop/C++/nibbler/plop
// 
// Made by mael charles
// Login   <charle_b@epitech.net>
// 
// Started on  Thu Mar 14 09:55:42 2013 mael charles
// Last update Sat Mar 23 16:35:54 2013 mael charles
//

#include "../core/IDisplayModule.hh"
#include "Init.hh"
#include "Event.hh"

extern "C"
{
  IDisplayModule *entry_point()
  {
    return (new Init());
  }
}

Init::Init()
{
}

Init::~Init()
{
}

void	Init::initWindow(int x, int y, int ac, char **av)
{
  (void)ac;
  (void)av;
  if (!al_init())
    throw Error("Allegro init fail");
  if (!al_init_image_addon())
    throw Error("Allegro image addon fail");
  if (!al_install_keyboard())
    throw Error("Allegro keyboard fail");
  if (!(this->display = al_create_display(800, 600)))
    throw Error("Allegro create display fail");
  if (!(this->event_queue = al_create_event_queue()))
    throw Error("Allegro event fail");
  if (!(this->timer = al_create_timer(1.0 / 5)))
    throw Error("Allegro timer fail");
  if (!(this->snake = al_create_bitmap(10, 10)))
    throw Error("Allegro create bitmap fail");
  al_register_event_source(this->event_queue, al_get_display_event_source(this->display));
  al_register_event_source(this->event_queue, al_get_timer_event_source(this->timer));
  al_register_event_source(this->event_queue, al_get_keyboard_event_source());
  Event	event(this->display, this->event_queue, this->timer, x, y);
}
