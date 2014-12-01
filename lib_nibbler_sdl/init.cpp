//
// init.cpp for init in /home/bettin_j//Dropbox/Epitech/Projets/Nibbler/lib_nibbler_sdl
// 
// Made by jordan bettin
// Login   <bettin_j@epitech.net>
// 
// Started on  Thu Mar 14 18:46:44 2013 jordan bettin
// Last update Sun Mar 24 00:05:16 2013 mael charles
//

#include "init.hh"

extern "C"
{
  IDisplayModule	*entry_point()
  {
    return (new Init());
  }
}

Init::Init()
  : _x(0), _y(0)
{}

Init::~Init()
{}

void	Init::initWindow(int x, int y, int ac, char **av)
{
  this->_x = x;
  this->_y = y;

  if (ac != 4)
    {
      std::cerr << "Usage : ./lib_nibbler_sdl.so HEIGHT WIDTH" << std::endl;
      exit(EXIT_FAILURE);
    }

  Window	window(av[1], av[2]);
}
