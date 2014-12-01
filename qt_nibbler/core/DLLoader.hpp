//
// DLLoader.hpp for DLLoader in /home/caille_l//Documents/cpp/tp_nibbler/ex3
// 
// Made by louis cailleux
// Login   <caille_l@epitech.net>
// 
// Started on  Tue Mar 12 11:33:35 2013 louis cailleux
// Last update Sun Mar 24 00:33:47 2013 louis cailleux
//

#include "DLLoader.hh"

template <typename T>
DLLoader<T>::DLLoader()
  : _lib(NULL)
{
}

template <typename T>
DLLoader<T>::~DLLoader()
{
}

template <typename T>
void	DLLoader<T>::openLibrary(const char *libname)
{
  if ((this->_lib = dlopen(libname, RTLD_LAZY)) == NULL)
    throw Exception("Library can't be loaded.");
}

template <typename T>
void	DLLoader<T>::loadLibrary()
{
  void	*ptr;
  
  if ((ptr = dlsym(this->_lib, "entry_point")) == NULL)
    throw Exception("Library has no entry point.");
  else 
    this->_ptr = reinterpret_cast<IDisplayModule *(*)()>(ptr);
}

template <typename T>
T	*DLLoader<T>::getInstance()
{
  return (this->_ptr());
}

template <typename T>
void	DLLoader<T>::closeLibrary()
{
  dlclose(this->_lib);
}
