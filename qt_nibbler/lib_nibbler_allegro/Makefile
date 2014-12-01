##
## Makefile for Makefile in /home/charle_b//Desktop/C++/nibbler/plop
## 
## Made by mael charles
## Login   <charle_b@epitech.net>
## 
## Started on  Tue Mar 19 09:33:31 2013 mael charles
## Last update Sat Mar 23 22:53:25 2013 mael charles
##

NAME=	lib_nibbler_allegro.so

SRC=	Event.cpp		\
	Init.cpp		\
	Exception.cpp		\
	../core/Snake.cpp	\
	../core/Collision.cpp	\
	../core/Exception.cpp	\
	../core/Apple.cpp

OBJ=	$(SRC:.cpp=.o)

CXXFLAGS=	-W -Wall -Werror

LIB=	-I/usr/include/allegro5 -L/usr/lib -lallegro -lallegro_image

LIBSO=	-fPIC -shared

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ $(LIBSO) $(SRC) -o $(NAME) $(LIB)
	cp $(NAME) ../

re:	fclean all

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)