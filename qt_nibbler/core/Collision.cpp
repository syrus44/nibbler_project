//
// Collision.cpp for Collision in /home/caille_l//Dropbox/Nibbler/core
// 
// Made by louis cailleux
// Login   <caille_l@epitech.net>
// 
// Started on  Sat Mar 23 16:51:05 2013 louis cailleux
// Last update Sat Mar 23 23:17:58 2013 louis cailleux
//

#include "Collision.hh"

Collision::Collision(int x, int y)
{
  this->_height = y;
  this->_width = x;
}

Collision::~Collision()
{
}

void	Collision::Areasize()
{
  if (this->_height < 10 || this->_width < 10)
    throw Exception("Area size can't be too small, null or negative");
  if (this->_width > 800 || this->_height > 600)
    throw Exception("Area size can't be greater than window size"); 
}

bool	Collision::offLimits(std::pair<int, int> head, int flag)
{
  int	Xhead = head.first;
  int	Yhead = head.second;
  int   leftBorder = 0;
  int   topBorder = 0;
  if (flag == 0)
    {
      leftBorder = ((800 - this->_height) / 2);
      topBorder = ((600 - this->_height) / 2);
    }
  int	rightBorder = leftBorder + this->_width;
  int	bottomBorder = topBorder + this->_height;
  if (Xhead < leftBorder || Xhead > rightBorder)
    {
      std::cout << "you loose." << std::endl;
      return (true);
    }
  if (Yhead < topBorder || Yhead > bottomBorder)
    {
      std::cout << "You loose." << std::endl;
      return (true);
    }
  return (false);
}

bool	Collision::eating(Snake *snake, Apple *apple)
{
  int	Xhead = snake->getSnake().front().first;
  int	Yhead = snake->getSnake().front().second;
  int	diffX = apple->getPosX() - Xhead;
  int	diffY = apple->getPosY() - Yhead;

  if (diffX < 0)
    diffX *= -1;
  if (diffY < 0)
    diffY *= -1;
  if (diffX < 10 && diffY < 10) 
    {
      apple->Shuffle();
      apple->incScore();
      snake->eat();
    }
  else
    {
      if (eatTail(snake))
	return (true);
    }
  return (false);
}

bool	Collision::eatTail(Snake *snake)
{
  std::list< std::pair<int, int> > coord = snake->getSnake();
  int	x = coord.front().first;
  int	y = coord.front().second;
  int	i = 0;
  
  for (std::list< std::pair<int, int> >::iterator it = coord.begin(); it != coord.end(); ++it)
    {
      if (i != 0)
	{
	  if (x == it->first && y == it->second)
	    {
	      std::cout << "You loose." << std::endl;
	      return (true);
	    }
	}
      i++;
    }
  return(false);
}

