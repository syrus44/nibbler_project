//
// apple.cpp for apple in /home/bettin_j//Dropbox/Epitech/Projets/Nibbler/lib_nibbler_sdl
// 
// Made by jordan bettin
// Login   <bettin_j@epitech.net>
// 
// Started on  Thu Mar 14 10:29:40 2013 jordan bettin
// Last update Sat Mar 23 21:58:06 2013 louis cailleux
//

#include "Apple.hh"

Apple::Apple(int w, int h)
{
  srand(time(NULL));
  this->appleScore = 0;
  this->posX = rand() % w;
  this->posY = rand() % h;
  this->_h = h;
  this->_w = w;
}

Apple::~Apple()
{}

int	Apple::getScore() const
{
  return (this->appleScore);
}

void	Apple::incScore()
{
  this->appleScore++;
}

int	Apple::getPosX() const
{
  return (this->posX);
}

void	Apple::Shuffle()
{
  this->posX = rand() % this->_w;
  this->posY = rand() % this->_h;
}

int	Apple::getPosY() const
{
  return (this->posY);
}

void	Apple::setPosX(int x)
{
  this->posX = x;
}

void	Apple::setPosY(int y)
{
  this->posY = y;
}
