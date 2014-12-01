//
// Exception.cpp for Nibbler in /home/caille_l//Dropbox/Nibbler/core
// 
// Made by louis cailleux
// Login   <caille_l@epitech.net>
// 
// Started on  Sat Mar 16 11:16:23 2013 louis cailleux
// Last update Sat Mar 16 11:16:25 2013 louis cailleux
//

#include "Exception.hh"

Exception::Exception(const std::string &msg) throw()
{
  this->_msg = msg;
}

Exception::~Exception() throw()
{
}

const char*             Exception::what() const throw()
{
  return (this->_msg.c_str());
}
