//
// window.hh for window in /home/bettin_j//Dropbox/Epitech/Projets/Nibbler/lib_nibbler_sdl
// 
// Made by jordan bettin
// Login   <bettin_j@epitech.net>
// 
// Started on  Thu Mar 14 11:20:08 2013 jordan bettin
// Last update Sun Mar 24 00:05:26 2013 mael charles
//

#ifndef WINDOW_HH
#define	WINDOW_HH

#include <iostream>
#include <sstream>
#include <SDL/SDL.h>

#include "../core/Snake.hh"
#include "display.hh"
#include "apple.hh"

#define	MAX_H		800
#define	MAX_W		600
#define	SCR_BPP		32
#define	SNAKE		"imgs/sdl_snake.bmp"

class	Window
{
protected:
  SDL_Surface	*screen;
  int		windowHeight;
  int		windowWidth;
  Snake		*core;
  Display	*my;
  Apple		*myApple;
  SDL_Rect	arena;
  SDL_Surface	*background;
  bool		statCollide;

public:
  Window(char *, char *);
  ~Window();
  int	getHeight() const;
  int	getWidth() const;
  bool	getStatCollide() const;
  void	setHeight(char *);
  void	setWidth(char *);
  void	createWindow(int, int);
  void	createArena(int, int);
  void	loadBackground();
  void	manageEvents();
  void	exitGame();
  bool	checkCollides(SDL_Rect, SDL_Rect);
  void	clearScreen();
};

#endif
