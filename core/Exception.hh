//
// Exception.hh for Nibbler in /home/caille_l//Dropbox/Nibbler/core
// 
// Made by louis cailleux
// Login   <caille_l@epitech.net>
// 
// Started on  Sat Mar 16 11:08:24 2013 louis cailleux
// Last update Sat Mar 16 11:08:26 2013 louis cailleux
//

#ifndef	EXCEPTION_HH
#define	EXCEPTION_HH

#include <iostream>
#include <exception>

class	Exception : public std::exception
{
  std::string	_msg;
  
public:
  Exception (std::string const &msg) throw();
  virtual ~Exception() throw();
  virtual const char* what() const throw();
};

#endif
