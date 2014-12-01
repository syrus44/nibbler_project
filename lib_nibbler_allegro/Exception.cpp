//
// Exception.cpp for Ecxeption in /home/charle_b//Desktop/C++/nibbler/plop
// 
// Made by mael charles
// Login   <charle_b@epitech.net>
// 
// Started on  Tue Mar 19 09:24:42 2013 mael charles
// Last update Tue Mar 19 10:22:25 2013 mael charles
//

#include "Exception.hh"

Error::Error(std::string errcode) throw(): _msg(errcode)
{
  this->_msg = errcode;
}

Error::~Error() throw()
{
}

const char * Error::what() const throw()
{
  return (this->_msg.c_str());
}
