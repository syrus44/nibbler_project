##
## Makefile for Nibbler in /home/caille_l//Dropbox/Nibbler/qt_nibbler
## 
## Made by louis cailleux
## Login   <caille_l@epitech.net>
## 
## Started on  Sun Mar 24 00:02:05 2013 louis cailleux
## Last update Sun Mar 24 00:58:25 2013 mael charles
##

NAME	=	lib_nibbler_qt.so

SRCS	=	Init.cpp		\
		Window.cpp		\
		GameArea.cpp		\
		Table.cpp		\
		moc_Window.cpp		\
		../core/Snake.cpp	\
		../core/Apple.cpp	\
		../core/Collision.cpp	\
		../core/Exception.cpp   \


OBJS	=	$(SRCS:.cpp=.o)

RM	=	rm -f

CXXFLAGS=	-W -Wall -Werror -Wextra

LDFLAGS	=	-shared -fPIC

LDLIB	=	-L/usr/lib64 -lQtGui -L/usr/lib64 -L/usr/X11R6/lib64 -lQtCore -lpthread

LDINC   =	-I/usr/share/qt4/mkspecs/default -I. -I/usr/include/QtCore -I/usr/include/QtGui -I/usr/include -I.

DUST	=	*~ \#*\#

CC	=	g++

all	:	$(NAME)

$(NAME)	:	
		$(CC) $(LDLIB) $(SRCS) $(LDINC) $(LDFLAGS) -o $(NAME)
		mv $(NAME) ../

dust	:
		$(RM) $(DUST)

clean	:	dust
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all