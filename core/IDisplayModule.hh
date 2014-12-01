//
// IDisplayModule.hh for ex2 in /home/caille_l//Documents/cpp/tp_nibbler/ex2
// 
// Made by louis cailleux
// Login   <caille_l@epitech.net>
// 
// Started on  Mon Mar 11 17:27:58 2013 louis cailleux
// Last update Thu Mar 14 16:52:50 2013 louis cailleux
//

#ifndef IDISPLAYMODULE_HH
#define IDISPLAYMODULE_HH

#include <iostream>

class IDisplayModule
{
public:
  virtual ~IDisplayModule() {};
  virtual void initWindow(int, int, int, char **) = 0;
};

#endif
