//
// Table.cpp for Nibbler in /home/caille_l//Dropbox/Nibbler
// 
// Made by louis cailleux
// Login   <caille_l@epitech.net>
// 
// Started on  Thu Mar 21 12:19:25 2013 louis cailleux
// Last update Sat Mar 23 20:12:59 2013 louis cailleux
//

#include "Table.hh"

Table::Table(int x, int y, std::list<_coord>snake, Apple *apple)
{
  this->_snake = snake;
  this->_apple = apple;
  this->_snakePic = new QPixmap("./imgs/snake.png");
  this->_applePic = new QPixmap("./imgs/apple.png");
  this->setFixedSize(x, y);
}

void    Table::move(const std::list<_coord> &snake)
{
    this->_snake = snake;
    repaint();
}

Table::~Table()
{
    delete (this->_snakePic);
}

void Table::paintEvent(QPaintEvent *)
{
    QPainter    paint(this);

    int i = 0;
    if (!(this->_snake.empty()))
      {
	for (std::list<_coord>::iterator it = this->_snake.begin(); it != this->_snake.end(); ++it)
	  {
	    paint.drawPixmap(it->first, it->second, 10, 10, *(this->_snakePic));
            i++;
	  }
      }
    paint.drawPixmap(this->_apple->getPosX(), this->_apple->getPosY(), 10, 10, *(this->_applePic));
    this->setAutoFillBackground(true);
}
