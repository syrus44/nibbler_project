//
// apple.hh for apple in /home/bettin_j//Dropbox/Epitech/Projets/Nibbler/lib_nibbler_sdl
// 
// Made by jordan bettin
// Login   <bettin_j@epitech.net>
// 
// Started on  Thu Mar 14 10:28:02 2013 jordan bettin
// Last update Sat Mar 23 21:58:39 2013 louis cailleux
//

#ifndef APPLE_HH
#define	APPLE_HH

#include <iostream>
#include <cstdlib>
#include <ctime>

class	Apple
{
protected:
  int	appleScore;
  int	posX;
  int	posY;
  int	_h;
  int	_w;

public:
  Apple(int, int);
  ~Apple();
  int	getScore() const;
  int	getPosX() const;
  int	getPosY() const;
  void	incScore();
  void	setPosX(int);
  void	setPosY(int);
  void	Shuffle();
};

#endif
