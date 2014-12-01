//
// Table.hh for Nibbler in /home/caille_l//Dropbox/Nibbler
// 
// Made by louis cailleux
// Login   <caille_l@epitech.net>
// 
// Started on  Thu Mar 21 12:19:39 2013 louis cailleux
// Last update Sun Mar 24 00:29:44 2013 louis cailleux
//

#ifndef TABLE_HH
#define TABLE_HH

#include <QWidget>
#include <QPainter>
#include <QPalette>
#include <iostream>
#include <QApplication>
#include "../core/Snake.hh"
#include "../core/Apple.hh"

class Table : public QWidget
{
  QPixmap *_snakePic;
  Apple	  *_apple;
  QPixmap *_applePic;
  std::list<_coord>   _snake;
  
public:
  Table(int, int, std::list<_coord>, Apple *);
  ~Table();
  void    move(std::list<_coord> const &);
protected:
    void    paintEvent(QPaintEvent *);
};

#endif // TABLE_HH
