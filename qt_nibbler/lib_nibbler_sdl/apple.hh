//
// apple.hh for apple in /home/bettin_j//Dropbox/Epitech/Projets/Nibbler/lib_nibbler_sdl
// 
// Made by jordan bettin
// Login   <bettin_j@epitech.net>
// 
// Started on  Thu Mar 14 10:28:02 2013 jordan bettin
// Last update Fri Mar 22 10:31:41 2013 jordan bettin
//

#ifndef APPLE_HH
#define	APPLE_HH

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <SDL/SDL.h>

#define	PIXEL_SIZE	10
#define	SCR_BPP		32

class	Apple
{
protected:
  int	appleScore;
  int	posX;
  int	posY;
  SDL_Surface	*p;
  SDL_Rect	rect;

public:
  Apple(int, int);
  ~Apple();
  int	getScore() const;
  int	getPosX() const;
  int	getPosY() const;
  void	setScore(int);
  void	setPosX(int);
  void	setPosY(int);
  void	displayApple(SDL_Surface *);
};

#endif
