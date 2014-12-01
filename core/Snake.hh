//
// Snake.hh for Nibbler in /home/caille_l//Dropbox/Nibbler/core
// 
// Made by louis cailleux
// Login   <caille_l@epitech.net>
// 
// Started on  Sat Mar 16 14:02:55 2013 louis cailleux
// Last update Sat Mar 23 22:12:17 2013 louis cailleux
//

#ifndef SNAKE_HH
#define SNAKE_HH

#include "IDisplayModule.hh"
#include <iostream>
#include <list>
#include <utility>

typedef std::pair<int, int>	_coord;

enum Direction
  {
    NORTH,
    SOUTH,
    WEST,
    EAST,
    EXIT
  };

class Snake
{
protected:
  Direction	snakeDirection;
  std::list< _coord >    _snake;
  bool			_left;
  bool			_right;
  bool			_exit;
public:
  Snake(int, int);
  Snake(Snake const &);
  Snake & operator=(Snake const &);
  void addBlock(int x, int y);
  std::list<_coord> getSnake() const;
  void tail();
  void move();
  void line();
  void eat();
  void setLib(IDisplayModule*);
  void setLeft(bool);
  void setRight(bool);
  void setExit(bool);
  Direction getDirection() const;
  bool getLeft() const;
  bool getRight() const;
  ~Snake();
};

#endif // SNAKE_HH
