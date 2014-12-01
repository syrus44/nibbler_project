//
// Window.hh for nibbler in /home/caille_l//Documents/cpp/qt_nibbler/qt_nibbler
// 
// Made by louis cailleux
// Login   <caille_l@epitech.net>
// 
// Started on  Tue Mar 12 18:39:57 2013 louis cailleux
// Last update Sat Mar 23 20:02:05 2013 louis cailleux
//

#ifndef WINDOW_HH
#define WINDOW_HH

#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QtGui>
#include <iostream>
#include <QKeyEvent>
#include "GameArea.hh"
#include "../core/IDisplayModule.hh"
#include "../core/Snake.hh"
#include "../core/Collision.hh"
#include "../core/Apple.hh"

class Window : public QWidget
{
  Q_OBJECT
  int _winX;
  int _winY;
  Snake     *_core;
  GameArea  *_gameZone;
  Table     *_table;
  QTimer    *_timer;
  Collision *_col;
  Apple	    *_apple;
public:
  Window(int, int, int, int);
  ~Window();
  void    initArea();
  void    update();
public slots:
  void refresh();
protected:
  virtual void keyPressEvent(QKeyEvent *e);
};

#endif // WINDOW_HH
