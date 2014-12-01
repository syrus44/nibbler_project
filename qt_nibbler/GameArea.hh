//
// GameArea.hh for nibbler in /home/caille_l//Documents/cpp/qt_nibbler/qt_nibbler
// 
// Made by louis cailleux
// Login   <caille_l@epitech.net>
// 
// Started on  Wed Mar 13 14:15:11 2013 louis cailleux
// Last update Wed Mar 13 14:15:13 2013 louis cailleux
//

#ifndef GAMEAREA_HH
#define GAMEAREA_HH

#include <QPainter>
#include <QtGui>
#include "Table.hh"

class GameArea : public QWidget
{
    int     _sizeX;
    int     _sizeY;
    int     _snakeX;
    int     _snakeY;
    QPixmap     *_snake;
    QGridLayout *_layout;
public:
    GameArea(int x, int y);
    ~GameArea();
    void gameTable(Table *table);
    void update();
    Table getSnake() const;
protected:
    virtual void paintEvent(QPaintEvent *);
};

#endif // GAMEAREA_HH
