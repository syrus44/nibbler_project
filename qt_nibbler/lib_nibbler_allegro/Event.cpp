//
// Event.cpp for event in /home/charle_b//Desktop/C++/nibbler/plop
// 
// Made by mael charles
// Login   <charle_b@epitech.net>
// 
// Started on  Thu Mar 14 13:52:21 2013 mael charles
// Last update Sun Mar 24 00:29:02 2013 mael charles
//

#include "Event.hh"

Event::Event(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_TIMER *timer, int x, int y)
{
  this->_core = new Snake(800, 600);
  this->_snake = this->_core->getSnake();
  this->_display = display;
  this->_event_queue = event_queue;
  this->_timer = timer;
  this->_background = al_load_bitmap("imgs/snake_allegro.bmp");
  if (!this->_background)
    throw Error("Allegro load bitmap fail");
  this->_imgapple = al_create_bitmap(10, 10);
  this->_block = al_create_bitmap(10, 10);
  this->_gamearea = al_create_bitmap(x, y);
  this->doexit = false;
  this->drawSnake();
  this->pos_x = (800 - x) / 2;
  this->pos_y = (600 - y) / 2;
  this->_coll = new Collision(x, y);
  this->_apple = new Apple(x, y);
  this->_apple->setPosX(this->_apple->getPosX() + this->pos_x);
  this->_apple->setPosY(this->_apple->getPosY() + this->pos_y);
  this->findEvent();
}

Event::~Event()
{
  delete (this->_core);
  delete (this->_coll);
  delete (this->_apple);
}

void	Event::findEvent()
{
  int	tmp = 0;

  al_set_target_bitmap(this->_block);
  al_clear_to_color(al_map_rgb(0, 51, 0));
  al_set_target_bitmap(this->_imgapple);
  al_clear_to_color(al_map_rgb(255, 0, 0));
  al_set_target_bitmap(this->_gamearea);
  al_clear_to_color(al_map_rgb(155, 255, 153));
  al_set_target_bitmap(al_get_backbuffer(this->_display));
  al_flip_display();
  al_start_timer(this->_timer);
  while (!this->doexit)
    {
      al_wait_for_event(this->_event_queue, &ev);
      if (this->ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
        doexit = true;
      else
	{
	  this->checkEvent();
	  if (this->_coll->eating(this->_core, this->_apple))
	    break;
	}
      if (al_is_event_queue_empty(this->_event_queue))
	{	  
	  drawImage();
	  if ((this->_coll->offLimits(this->_core->getSnake().front(), 0)))
	    break;
	  this->_core->move();
	  this->_snake = this->_core->getSnake();
	  tmp = this->_apple->getPosX();
	  if (this->_coll->eating(this->_core, this->_apple))
	    break;
	  if (this->_apple->getPosX() != tmp)
	    {
	      this->_apple->setPosX(this->_apple->getPosX() + this->pos_x);
	      this->_apple->setPosY(this->_apple->getPosY() + this->pos_y);
	    }
	}
    }
}

void	Event::drawImage()
{
  al_clear_to_color(al_map_rgb(0, 0, 0));
  al_draw_bitmap(this->_background, 0, 0, 0);
  al_draw_bitmap(this->_gamearea, this->pos_x, this->pos_y, 0);
  drawSnake();
  al_draw_bitmap(this->_imgapple, this->_apple->getPosX(), this->_apple->getPosY(), 0);
  al_flip_display();
}

void	Event::drawSnake()
{
  for (std::list<_coord>::iterator it = this->_snake.begin(); it != this->_snake.end(); ++it)
    al_draw_bitmap(this->_block, it->first, it->second, 0);
}

void	Event::checkEvent()
{
  switch (ev.keyboard.keycode)
    {
    case ALLEGRO_KEY_LEFT:
      this->_core->setLeft(true);
      this->_core->setRight(false);
      this->_core->move();
      this->_snake = this->_core->getSnake();
      break;
    case ALLEGRO_KEY_RIGHT:
      this->_core->setLeft(false);
      this->_core->setRight(true);
      this->_core->move();
      this->_snake = this->_core->getSnake();
      break;
    }
}
