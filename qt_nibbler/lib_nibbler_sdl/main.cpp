//
// main.cpp for main in /home/bettin_j//Dropbox/Epitech/Projets/Nibbler/lib_nibbler_sdl
// 
// Made by jordan bettin
// Login   <bettin_j@epitech.net>
// 
// Started on  Thu Mar 14 11:47:19 2013 jordan bettin
// Last update Thu Mar 14 11:48:29 2013 jordan bettin
//

#include "window.hh"

int	main(int ac, char **av)
{
  if (ac != 3)
    {
      std::cerr << "Usage : ./lib_nibbler_sdl HEIGHT WIDTH" << std::endl;
      exit(EXIT_FAILURE);
    }
  Window	window(av[1], av[2]);

  return (EXIT_SUCCESS);
}
