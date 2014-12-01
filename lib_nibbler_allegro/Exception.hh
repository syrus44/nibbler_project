//
// Exception.hh for Exception in /home/charle_b//Desktop/C++/nibbler/plop
// 
// Made by mael charles
// Login   <charle_b@epitech.net>
// 
// Started on  Tue Mar 19 09:28:08 2013 mael charles
// Last update Tue Mar 19 10:21:06 2013 mael charles
//

#ifndef EXCEPTION_HH
#define EXCEPTION_HH

#include <stdexcept>
#include <iostream>
#include <sstream>

class Error : public std::exception
{
  std::string	_msg;

public:
  Error(std::string errcode) throw();
  virtual ~Error() throw();

  const char * what() const throw();
};

#endif
