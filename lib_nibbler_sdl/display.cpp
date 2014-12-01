//
// display.cpp for display in /home/bettin_j//Dropbox/Epitech/Projets/Nibbler/lib_nibbler_sdl
// 
// Made by jordan bettin
// Login   <bettin_j@epitech.net>
// 
// Started on  Tue Mar 19 17:05:30 2013 jordan bettin
// Last update Fri Mar 22 14:07:09 2013 jordan bettin
//

#include "display.hh"

Display::Display(Snake *s)
{
  this->posX = 0;
  this->posY = 0;
  this->snakeLength = 3;
  this->snakeBody = s->getSnake();
  this->pixel = SDL_CreateRGBSurface(SDL_SWSURFACE, PIXEL_SIZE, PIXEL_SIZE, SCR_BPP, 0, 0, 0, 0);
}

Display::~Display()
{}

int	Display::getLength() const
{
  return (this->snakeLength);
}

int	Display::getPosX() const
{
  return (this->posX);
}

int	Display::getPosY() const
{
  return (this->posY);
}

SDL_Rect	Display::getSnakeBody() const
{
  return (this->body);
}

void	Display::setPosX(int x)
{
  this->posX = x;
}

void	Display::setPosY(int y)
{
  this->posY = y;
}

void	Display::setSnake(std::list<_coord> s)
{
  this->snakeBody = s;
}

void	Display::displaySnake(SDL_Surface *screen)
{
  if (!(this->snakeBody.empty()))
    {
      for (std::list<_coord>::iterator it = this->snakeBody.begin() ; it != this->snakeBody.end() ; ++it)
	{
	  this->body.x = it->first;
	  this->body.y = it->second;
	  SDL_FillRect(this->pixel, NULL, SDL_MapRGB(screen->format, 102, 204, 204));
	  SDL_BlitSurface(this->pixel, NULL, screen, &(this->body));
	  SDL_Flip(screen);
	}
    }
}
