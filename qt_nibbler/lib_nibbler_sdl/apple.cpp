//
// apple.cpp for apple in /home/bettin_j//Dropbox/Epitech/Projets/Nibbler/lib_nibbler_sdl
// 
// Made by jordan bettin
// Login   <bettin_j@epitech.net>
// 
// Started on  Thu Mar 14 10:29:40 2013 jordan bettin
// Last update Sat Mar 23 15:26:35 2013 mael charles
//

#include "apple.hh"

Apple::Apple(int h, int w)
{
  srand(time(NULL));
  this->appleScore = 10;
  this->posX = rand() % h;
  this->posY = rand() % w;
  this->p = SDL_CreateRGBSurface(SDL_SWSURFACE, PIXEL_SIZE, PIXEL_SIZE, SCR_BPP, 255, 255, 255, 0);
}

Apple::~Apple()
{}

int	Apple::getScore() const
{
  return (this->appleScore);
}

void	Apple::setScore(int s)
{
  this->appleScore = s;
}

int	Apple::getPosX() const
{
  return (this->posX);
}

int	Apple::getPosY() const
{
  return (this->posY);
}

void	Apple::setPosX(int x)
{
  this->posX = x;
  this->rect.x = PIXEL_SIZE * x;
}

void	Apple::setPosY(int y)
{
  this->posY = y;
  this->rect.y = PIXEL_SIZE * y;
}

void	Apple::displayApple(SDL_Surface *screen)
{
  this->rect.x = this->getPosX();
  this->rect.y = this->getPosY();
  SDL_FillRect(this->p, NULL, SDL_MapRGB(screen->format, 109, 7, 26));
  SDL_BlitSurface(this->p, NULL, screen, &(this->rect));
  SDL_Flip(screen);
}
