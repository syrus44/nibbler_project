//
// Init.hh for Nibbler in /home/caille_l//Dropbox/Nibbler/qt_nibbler
// 
// Made by louis cailleux
// Login   <caille_l@epitech.net>
// 
// Started on  Sun Mar 24 00:27:25 2013 louis cailleux
// Last update Sun Mar 24 00:27:26 2013 louis cailleux
//

#ifndef INIT_HH
#define INIT_HH

#include "../core/IDisplayModule.hh"
#include "Window.hh"

class Init : public IDisplayModule
{
    Window  *_newin;
public:
    Init();
    ~Init();
    virtual void initWindow(int, int, int ac, char **av);
};

#endif // INIT_HH
