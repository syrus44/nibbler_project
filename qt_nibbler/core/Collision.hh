//
// Collision.hh for Nibbler in /home/caille_l//Dropbox/Nibbler
// 
// Made by louis cailleux
// Login   <caille_l@epitech.net>
// 
// Started on  Sat Mar 23 17:11:48 2013 louis cailleux
// Last update Sat Mar 23 21:37:28 2013 louis cailleux
//

#ifndef	COLLISION_HH
#define COLLISION_HH

#include "Exception.hh"
#include "Apple.hh"
#include "Snake.hh"

class Collision
{
  int	_height;
  int	_width;
public:
  Collision(int, int);
  ~Collision();
  void	Areasize();
  bool	eating(Snake *, Apple *);
  bool	offLimits(std::pair<int, int>, int flag);
  bool  eatTail(Snake *);
};

#endif
