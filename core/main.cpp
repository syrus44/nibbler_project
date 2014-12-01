//
// main.cpp for nibbler in /home/caille_l//Dropbox/Nibbler/core
// 
// Made by louis cailleux
// Login   <caille_l@epitech.net>
// 
// Started on  Thu Mar 14 10:54:50 2013 louis cailleux
// Last update Mon Mar 25 10:41:16 2013 louis cailleux
//

#include <sstream>
#include "DLLoader.hh"
#include "DLLoader.hpp"
#include "Snake.hh"
#include "Collision.hh"

int	main(int ac, char **av)
{
  int	x;
  int	y;
  DLLoader		<IDisplayModule>load;
  IDisplayModule	*mod;

  if (ac == 4)
    {
      std::istringstream	s1(av[1]);
      std::istringstream	s2(av[2]);
      s1 >> x;
      s2 >> y;
      Collision		col(x, y);
      try
	{
	  load.openLibrary(av[3]);
	  load.loadLibrary();
	  mod = load.getInstance();
	  col.Areasize();
	  mod->initWindow(x, y, ac, av);
	  load.closeLibrary();
	}
      catch (const Exception &e)
	{
	  std::cerr << "Error : " << e.what() << std::endl;
	}
    }
  return (0);
}
