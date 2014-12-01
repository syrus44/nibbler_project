//
// Init.cpp for nibbler in /home/caille_l//Documents/cpp/qt_nibbler
// 
// Made by louis cailleux
// Login   <caille_l@epitech.net>
// 
// Started on  Thu Mar 14 15:26:23 2013 louis cailleux
// Last update Thu Mar 21 12:19:14 2013 louis cailleux
//

#include "Init.hh"
#include <QApplication>

extern "C"
{
    IDisplayModule *entry_point()
    {
      return (new Init());
    }
}

Init::Init()
{
}

void Init::initWindow(int x, int y, int ac, char**av)
{
  QApplication    app(ac, av);
  this->_newin = new Window(800, 600, x, y);
  
  this->_newin->initArea();
  this->_newin->show();
  app.exec();
}

Init::~Init()
{
}
