//
// Event.hh for Event in /home/charle_b//Desktop/C++/nibbler/plop
// 
// Made by mael charles
// Login   <charle_b@epitech.net>
// 
// Started on  Sat Mar 16 11:37:22 2013 mael charles
// Last update Sat Mar 23 22:57:42 2013 mael charles
//

#ifndef EVENT_HH
#define EVENT_HH

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Init.hh"
#include "../core/Snake.hh"
#include "../core/Collision.hh"
#include "../core/Apple.hh"

enum KEYS
  {
    KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
  };

class Event
{
  std::list<_coord>	_snake;
  Snake			*_core;
  Collision		*_coll;
  Apple			*_apple;
  ALLEGRO_DISPLAY	*_display;
  ALLEGRO_EVENT_QUEUE	*_event_queue;
  ALLEGRO_TIMER		*_timer;
  ALLEGRO_BITMAP	*_block;
  ALLEGRO_BITMAP	*_gamearea;
  ALLEGRO_BITMAP	*_background;
  ALLEGRO_BITMAP	*_imgapple;
  ALLEGRO_EVENT		ev;
  bool			doexit;
  int			pos_x;
  int			pos_y;

public:
  Event(ALLEGRO_DISPLAY *, ALLEGRO_EVENT_QUEUE *, ALLEGRO_TIMER *, int, int);
  ~Event();

  void	findEvent();
  void	checkEvent();
  void	drawImage();
  void	drawSnake();
};

#endif
