//
// window.cpp for window in /home/bettin_j//Dropbox/Epitech/Projets/Nibbler/lib_nibbler_sdl
// 
// Made by jordan bettin
// Login   <bettin_j@epitech.net>
// 
// Started on  Thu Mar 14 11:23:17 2013 jordan bettin
// Last update Sun Mar 24 13:34:45 2013 jordan bettin
//

#include "window.hh"

Window::Window(char *height, char *width)
{
  this->setHeight(height);
  this->setWidth(width);
  this->core = new Snake(800, 600);
  this->my = new Display(this->core);
  this->myApple = new Apple(this->getHeight(), this->getWidth());
  this->createWindow(this->getHeight(), this->getWidth());
}

Window::~Window()
{  
  if (screen)
    delete this->screen;
  if (core)
    delete this->core;
  if (myApple)
    delete this->myApple;
  if (my)
    delete this->my;
}

int	Window::getHeight() const
{
  return (this->windowHeight);
}

int	Window::getWidth() const
{
  return (this->windowWidth);
}

bool	Window::getStatCollide() const
{
  return (this->statCollide);
}

void	Window::setHeight(char *h)
{
  std::stringstream	iss;
  int	tmp;

  iss.str(h);
  iss >> tmp;
  this->windowHeight = tmp;
}

void	Window::setWidth(char *w)
{
  std::stringstream	iss;
  int	tmp;

  iss.str(w);
  iss >> tmp;
  this->windowWidth = tmp;
}

void	Window::createWindow(int h, int w)
{
  int		stat;

  stat = SDL_Init(SDL_INIT_VIDEO);
  if (stat == -1)
    {
      std::cerr << "Video initialization failed ! STOP !" << std::endl;
      exit(EXIT_FAILURE);
    }
  atexit(SDL_Quit);
  this->screen = SDL_SetVideoMode(MAX_H, MAX_W, SCR_BPP, SDL_HWSURFACE | SDL_DOUBLEBUF);
  if (this->screen == NULL)
    {
      std::cerr << "Creating screen failed ! STOP !" << std::endl;
      exit(EXIT_FAILURE);
    }
  SDL_WM_SetCaption("Snake", NULL);
  this->loadBackground();
  this->createArena(h, w);
}

void	Window::loadBackground()
{
  this->background = SDL_LoadBMP(SNAKE);
  if (this->background == NULL)
    {
      std::cerr << "Loading image failed ! STOP !" << std::endl;
      exit(EXIT_FAILURE);
    }
  SDL_BlitSurface(this->background, NULL, this->screen, NULL); 
  SDL_Flip(this->screen);
}

void	Window::createArena(int h, int w)
{
  if ((h > 0 && h <= MAX_H - 0) || (w > 0 && w <= MAX_W - 0))
    {
      this->arena.x = (800 - w) / 2;
      this->arena.y = (600 - h) / 2;
      this->arena.w = w;
      this->arena.h = h;
      SDL_FillRect(this->screen, &(this->arena), SDL_MapRGB(this->screen->format, 0, 0, 0));
      SDL_Flip(this->screen);
      this->manageEvents();
    }
  else
    {
      std::cerr << "Height or width are too small or too big ! STOP !" << std::endl;
      exit(EXIT_FAILURE);
    }
}

void	Window::manageEvents()
{
  SDL_Event	event;
  bool		cont = true;

  this->statCollide = false;
  while (cont == true)
    {
      this->myApple->displayApple(this->screen);
      while (SDL_PollEvent(&event))
	{
	  switch(event.type)
	    {
	    case SDL_QUIT:
	      cont = false;
	      break;
	  
	    case SDL_KEYDOWN:

	      switch (event.key.keysym.sym)
		{
		case SDLK_LEFT:
		  this->core->setLeft(true);
		  this->core->setRight(false);
		  this->core->move();
		  this->my->setSnake(this->core->getSnake());
		  this->checkCollides(this->my->getSnakeBody(), this->arena);
		  this->clearScreen();
		  this->my->displaySnake(this->screen);
		  break;
	      
		case SDLK_RIGHT:
		  this->core->setLeft(false);
		  this->core->setRight(true);
		  this->core->move();
		  this->my->setSnake(this->core->getSnake());
		  this->checkCollides(this->my->getSnakeBody(), this->arena);
		  this->clearScreen();
		  this->my->displaySnake(this->screen);
		  break;

		case SDLK_ESCAPE:
		  this->exitGame();
		  break;
		  
		default:
		  break;
		};
	    default:
	      break;
	    };
	}
      this->core->move();
      this->my->setSnake(this->core->getSnake());
      this->checkCollides(this->my->getSnakeBody(), this->arena);
      this->clearScreen();
      this->my->displaySnake(this->screen);
      SDL_Delay(750);
    }
  this->exitGame();
}

bool	Window::checkCollides(SDL_Rect snake, SDL_Rect arena)
{
  if ((snake.x >= arena.w + arena.x) || (arena.w + arena.x <= snake.x) ||
      (snake.y >= arena.h + arena.y) || (arena.h + arena.y <= snake.y))
    {
      std::cerr << "Ouch ! Vous avez perdu !" << std::endl;
      this->exitGame();
      return (this->statCollide = true);
    }
  else
    return (this->statCollide = false);
}

void	Window::clearScreen()
{
  SDL_FillRect(this->screen, &(this->arena), SDL_MapRGB(this->screen->format, 0, 0, 0));
  SDL_Flip(this->screen);
  this->my->displaySnake(this->screen);
}

void	Window::exitGame()
{
  std::cout << "Merci d'avoir joué !" << std::endl;
  atexit(SDL_Quit);
  exit(EXIT_SUCCESS);
}
