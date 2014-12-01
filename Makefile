##
## Makefile for Makefile in /home/caille_l//Dropbox/Nibbler
## 
## Made by louis cailleux
## Login   <caille_l@epitech.net>
## 
## Started on  Thu Mar 14 10:35:19 2013 louis cailleux
## Last update Sun Mar 24 00:53:44 2013 louis cailleux
##

NAME	 = nibbler

ALLEGRO  = lib_nibbler_allegro.so

QT	 = lib_nibbler_qt.so

SDL	 = lib_nibbler_sdl.so

CC	 = g++

RM	 = rm -f

DUST	 = \#*\#

CXXFLAGS = -W -Wall -Werror -Wextra

CORE_DIR = ./core

ALLEGRO_DIR = ./lib_nibbler_allegro

SDL_DIR= ./lib_nibbler_sdl

QT_DIR= ./qt_nibbler

SRC	 = $(CORE_DIR)/main.cpp		\
	   $(CORE_DIR)/Exception.cpp	\
	   $(CORE_DIR)/Snake.cpp	\
	   $(CORE_DIR)/Collision.cpp	\
	   $(CORE_DIR)/Apple.cpp	

OBJ	 = $(SRC:.cpp=.o)

all:	$(NAME) $(ALLEGRO) $(SDL) $(QT)

$(ALLEGRO): 
	make -C $(ALLEGRO_DIR)

$(SDL):
	make -C $(SDL_DIR)

$(QT):
	make -C $(QT_DIR)	

$(NAME):	$(OBJ)
	echo $(ALLEGRO)
	$(CC)	-ldl -o	$(NAME)	$(OBJ)

clean:
	$(RM)	$(OBJ)
	$(RM)	$(DUST)
	$(RM)	*~

fclean:	clean
	$(RM)	$(NAME)
	$(RM)	$(ALLEGRO)
	$(RM)	$(SDL)
	$(RM)	$(QT)

re:	fclean 	all