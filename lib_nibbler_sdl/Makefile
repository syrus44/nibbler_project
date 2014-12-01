##
## Makefile for Makefile in /home/bettin_j//Dropbox/Epitech/Projets/Nibbler/lib_nibbler_sdl
## 
## Made by jordan bettin
## Login   <bettin_j@epitech.net>
## 
## Started on  Thu Mar 14 11:42:58 2013 jordan bettin
## Last update Sun Mar 24 00:08:31 2013 louis cailleux
##

NAME	=	lib_nibbler_sdl.so

SRCS	=	display.cpp	\
		apple.cpp	\
		window.cpp	\
		init.cpp	\
		../core/Snake.cpp

OBJS	=	$(SRCS:.cpp=.o)

RM	=	rm -f

CXXFLAGS=	-W -Wall -Werror -Wextra

LDFLAGS	=	-shared -fPIC

LDLIB	=	-lSDL

DUST	=	*~ \#*\#

CC	=	g++

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) -o $(NAME) $(SRCS) $(LDFLAGS) $(LDLIB)
		mv $(NAME) ../

dust	:
		$(RM) $(DUST)

clean	:	dust
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all
