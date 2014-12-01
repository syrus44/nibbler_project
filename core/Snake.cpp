//
// Snake.cpp for Nibbler in /home/caille_l//Dropbox/Nibbler/core
// 
// Made by louis cailleux
// Login   <caille_l@epitech.net>
// 
// Started on  Sat Mar 16 14:02:32 2013 louis cailleux
// Last update Sat Mar 23 23:22:05 2013 louis cailleux
//

#include "Snake.hh"

Snake::Snake(int x, int y)
  : snakeDirection(EAST), _left(false), _right(false), _exit(false)
{
  this->addBlock((x /2), (y / 2));
  this->addBlock((x / 2), (y / 2) - 10);
  this->addBlock((x / 2), (y / 2) - 20);
  this->addBlock((x / 2), (y / 2) - 30);
}

Snake::Snake(Snake const & other)
{
    this->_snake = other.getSnake();
    this->snakeDirection = other.getDirection();
    this->_left = other.getLeft();
    this->_right = other.getRight();
}

Snake &	Snake::operator=(Snake const &other)
{
  if (this != &other)
    {
      this->_snake = other.getSnake();
      this->snakeDirection = other.getDirection();
      this->_left = other.getLeft();
      this->_right = other.getRight();
    }
    return (*this);
}

void    Snake::addBlock(int x, int y)
{
  this->_snake.push_front(std::make_pair(x, y));
}

void	Snake::eat()
{
  int x = this->_snake.front().first;
  int y = this->_snake.front().second;
  if (this->snakeDirection == WEST)
    x -= 10;
  else if (this->snakeDirection == EAST)
    x += 10;
  else if (this->snakeDirection == NORTH)
    y -= 10;
  else if (this->snakeDirection == SOUTH)
    y += 10;
  this->_snake.push_back(std::make_pair(x, y));
}

Direction	Snake::getDirection() const
{
  return (this->snakeDirection);
}

void	Snake::move()
{
  if (!(this->_snake.empty()))
    {
      if (this->snakeDirection == NORTH)
	{
	  if (this->_left == true)
	    this->snakeDirection = EAST;
	  else if (this->_right == true)
	    this->snakeDirection = WEST;
	}
      else if (this->snakeDirection == SOUTH)
	{
	  if (this->_left == true)
	    this->snakeDirection = WEST;
	  else if (this->_right == true)
	    this->snakeDirection = EAST;
	}
      else if (this->snakeDirection == EAST)
	{
	  if (this->_left == true)
	    this->snakeDirection = SOUTH;
	  else if (this->_right == true)
	    this->snakeDirection = NORTH;
	}
      else if (this->snakeDirection == WEST)
	{
	  if (this->_left == true)
	    this->snakeDirection = NORTH;
	  else if (this->_right == true)
	    this->snakeDirection = SOUTH;
	}
    }
    this->tail();
    this->setLeft(false);
    this->setRight(false);
}

void    Snake::tail()
{
    int x = this->_snake.front().first;
    int y = this->_snake.front().second;

    if (this->snakeDirection == WEST)
        this->addBlock(x - 10, y);
    else if (this->snakeDirection == EAST)
        this->addBlock(x + 10, y);
    else if (this->snakeDirection == NORTH)
        this->addBlock(x, y - 10);
    else if (this->snakeDirection == SOUTH)
        this->addBlock(x, y + 10);
    this->_snake.pop_back();
}

void	Snake::setExit(bool exit)
{
  this->_exit = exit;
}

std::list< std::pair<int, int> >  Snake::getSnake() const
{
    return (this->_snake);
}

void	Snake::setLeft(bool dir)
{
  this->_left = dir;
}

void	Snake::setRight(bool dir)
{
  this->_right = dir;
}

bool	Snake::getLeft() const
{
  return (this->_left);
}

bool	Snake::getRight() const
{
  return (this->_right);
}

Snake::~Snake()
{
}
