//
// init.hh for init in /home/charle_b//Desktop/C++/nibbler/plop
// 
// Made by mael charles
// Login   <charle_b@epitech.net>
// 
// Started on  Thu Mar 14 09:48:43 2013 mael charles
// Last update Sat Mar 23 14:35:50 2013 mael charles
//

#ifndef INIT_HH
#define INIT_HH

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "../core/IDisplayModule.hh"
#include "Exception.hh"

class Init : public IDisplayModule
{
  ALLEGRO_DISPLAY	*display;
  ALLEGRO_EVENT_QUEUE	*event_queue;
  ALLEGRO_TIMER		*timer;
  ALLEGRO_BITMAP	*snake;
  bool			doexit;

public:
  Init();
  ~Init();

  void	initWindow(int, int, int, char **);
};

#endif
