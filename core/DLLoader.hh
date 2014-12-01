//
// DLLoader.hh for DLLoader in /home/caille_l//Documents/cpp/tp_nibbler/ex2
// 
// Made by louis cailleux
// Login   <caille_l@epitech.net>
// 
// Started on  Mon Mar 11 18:01:49 2013 louis cailleux
// Last update Sat Mar 16 11:20:18 2013 louis cailleux
//

#include <iostream>
#include "IDisplayModule.hh"
#include <dlfcn.h>
#include <unistd.h>
#include <stdlib.h>
#include "Exception.hh"

#ifndef	DLLOADER_HH
#define DLLOADER_HH

template <class T>
class	DLLoader
{
  void	*_lib;
  T *(*_ptr)();

public:
  DLLoader();
  ~DLLoader();
  void	openLibrary(const char*);
  void	closeLibrary();
  void	loadLibrary();
  T *getInstance();
};

#endif
