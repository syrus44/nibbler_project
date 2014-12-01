//
// display.hh for display in /home/bettin_j//Dropbox/Epitech/Projets/Nibbler/lib_nibbler_sdl
// 
// Made by jordan bettin
// Login   <bettin_j@epitech.net>
// 
// Started on  Tue Mar 19 17:04:53 2013 jordan bettin
// Last update Fri Mar 22 11:13:44 2013 jordan bettin
//

#ifndef DISPLAY_HH
#define	DISPLAY_HH

#include <list>
#include <iostream>
#include <SDL/SDL.h>

#include "../core/Snake.hh"

#define	PIXEL_SIZE	10
#define	SCR_BPP		32

typedef std::pair<int, int>	_coord;

class	Display
{
protected:
  int	posX;
  int	posY;
  int	snakeLength;
  std::list<_coord>	snakeBody;
  SDL_Surface	*pixel;
  SDL_Rect	body;

public:
  Display(Snake *);
  ~Display();
  void	setPosX(int);
  void	setPosY(int);
  void	setSnake(std::list<_coord>);
  int	getLength() const;
  int	getPosX() const;
  int	getPosY() const;
  SDL_Rect getSnakeBody() const;
  void	displaySnake(SDL_Surface *);
};

#endif
