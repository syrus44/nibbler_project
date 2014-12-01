//
// GameArea.cpp for nibbler in /home/caille_l//Documents/cpp/qt_nibbler/qt_nibbler
// 
// Made by louis cailleux
// Login   <caille_l@epitech.net>
// 
// Started on  Wed Mar 13 14:15:30 2013 louis cailleux
// Last update Wed Mar 13 14:15:33 2013 louis cailleux
//

#include "GameArea.hh"

GameArea::GameArea(int x, int y)
{
    this->_sizeX = x;
    this->_sizeY = y;
    this->_layout = new QGridLayout;
}

void    GameArea::gameTable(Table *table)
{
    QPalette * p = new QPalette;

    p->setColor(QPalette::Window, Qt::black);
    table->setPalette(*p);
    table->setFixedSize(this->_sizeX, this->_sizeY);
    table->setAutoFillBackground(true);
    this->_layout->addWidget(table);
    this->setLayout(this->_layout);
}

void    GameArea::update()
{
    repaint();
}

GameArea::~GameArea()
{
    delete (this->_layout);
}

void GameArea::paintEvent(QPaintEvent *)
{
    QPainter    paint(this);
    QPixmap p;
    QString     str("./imgs/area.png");
    p.load(str);
    paint.drawPixmap(0, 0, p);
}
