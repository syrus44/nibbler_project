//
// Window.cpp for nibbler in /home/caille_l//Documents/cpp/qt_nibbler/qt_nibbler
// 
// Made by louis cailleux
// Login   <caille_l@epitech.net>
// 
// Started on  Tue Mar 12 18:39:24 2013 louis cailleux
// Last update Sun Mar 24 00:28:25 2013 louis cailleux
//

#include "Window.hh"

Window::Window(int x, int y, int zoneX, int zoneY)
{
  this->_winX = x;
  this->_winY = y;
  this->_core = new Snake(zoneX, zoneY);
  this->_gameZone = new GameArea(zoneX, zoneY);
  this->_apple = new Apple(zoneX, zoneY);
  this->_table = new Table(zoneX / 2, zoneY / 2, this->_core->getSnake(), this->_apple);
  this->setFixedSize(x, y);
  this->_timer = new QTimer(this);
  this->_col = new Collision(zoneX, zoneY);
  connect(this->_timer, SIGNAL(timeout()), this, SLOT(refresh()));
  this->_timer->start(100);
}

void    Window::initArea()
{
    QGridLayout *layout = new QGridLayout(this);

    layout->addWidget(this->_gameZone);
    this->setLayout(layout);
    this->setWindowTitle(tr("nibbler"));
    this->_gameZone->gameTable(this->_table);
}

void	Window::refresh()
{
  if (!this->_col->offLimits(this->_core->getSnake().front(), 1))
    {
      if (this->_col->eating(this->_core, this->_apple))
	this->close();
      this->_core->move();
      this->_table->move(this->_core->getSnake());
    }
  else
    this->close();
}

void    Window::update()
{
  if (this->_col->offLimits(this->_core->getSnake().front(), 1))
    this->close();
  else
    {
      this->_table->move(this->_core->getSnake());
      if (this->_col->eating(this->_core, this->_apple))
	this->close();
    }
}

void    Window::keyPressEvent(QKeyEvent *e)
{
  switch(e->key())
    {
    case Qt::Key_Escape:
      this->close();
      break;
    case Qt::Key_Left:
      this->_core->setLeft(true);
      this->_core->setRight(false);
      this->_core->move();
      if (!this->_col->offLimits(this->_core->getSnake().front(), 1))
	{
	  this->_table->move(this->_core->getSnake());
	  if (this->_col->eating(this->_core, this->_apple))
	    this->close();
	}
      else
	this->close();
      break;
    case Qt::Key_Right:
      this->_core->setRight(true);
      this->_core->setLeft(false);
      this->_core->move();
      if (!this->_col->offLimits(this->_core->getSnake().front(), 1))
	{
	  this->_table->move(this->_core->getSnake());
	  if (this->_col->eating(this->_core, this->_apple))
	    this->close();
	}
      else
	this->close();
      break;
    default: break;
    }
}

Window::~Window()
{
  delete (this->_col);
  delete (this->_timer);
  delete (this->_core);
  delete (this->_table);
  delete (this->_apple);
  delete (this->_gameZone);
}
