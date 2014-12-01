//
// init.hh for init in /home/bettin_j//Dropbox/Epitech/Projets/Nibbler/lib_nibbler_sdl
// 
// Made by jordan bettin
// Login   <bettin_j@epitech.net>
// 
// Started on  Thu Mar 14 18:46:51 2013 jordan bettin
// Last update Thu Mar 14 18:47:53 2013 jordan bettin
//

#ifndef	INIT_HH
#define	INIT_HH

#include "window.hh"
#include "../core/IDisplayModule.hh"

class	Init : public IDisplayModule
{
  int	_x;
  int	_y;

public:
  Init();
  ~Init();
  void	initWindow(int, int, int, char **);
};

#endif
