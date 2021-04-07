##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

#SHARED

SHARED_SRC =	Drawable.cpp	\
				ADisplayModule.cpp

SHARED_OBJ = $(SHARED_SRC:.cpp=.o)

#################################################################################

#SFML SOURCES

SFML_SRC = SFML/SfmlModule.cpp

SFML_OBJ = $(SFML_SRC:.cpp=.o)

SFML_NAME	=	arcade_sfml.so

SFML_LIB	=	-lsfml-graphics -lsfml-window -lsfml-system

#################################################################################

#SDL SOURCES

SDL_SRC	=	Sdl/Sdl.cpp

SDL_OBJ	=	$(SDL_SRC:.cpp=.o)

SDL_NAME	=	arcade_sdl2.so

SDL_LIB		=	-lSDL2main -lSDL2

#################################################################################

#NCURSE SOURCES

NCURSE_SRC	=	Ncurses/Ncurses.cpp

NCURSE_OBJ	=	$(NCURSE_SRC:.cpp=.o)

NCURSE_NAME	=	arcade_ncurses.so

NCURSE_LIB		=	-lncurses

#################################################################################

#VAR

CXX	=	g++

CPPFLAGS	=	-iquote./ -iquote../

CXXFLAGS	=	-Wall -Wextra -fPIC

DEST_DIRECTORY	=	../../lib

#################################################################################

#RULES

.PHONY: all
all: SFML SDL NCURSE
all:
	mv $(NCURSE_NAME) $(DEST_DIRECTORY)
	mv $(SFML_NAME) $(DEST_DIRECTORY)
	mv $(SDL_NAME) $(DEST_DIRECTORY)

#MAIN RULES

.PHONY: SFML
SFML: $(SFML_OBJ) $(SHARED_OBJ)
	$(CXX) -o $(SFML_NAME) $(SFML_OBJ) $(SHARED_OBJ) $(SFML_LIB) -shared

.PHONY: SDL
SDL: $(SDL_OBJ) $(SHARED_OBJ)
	$(CXX) -o $(SDL_NAME) $(SDL_OBJ) $(SHARED_OBJ) $(SDL_LIB) -shared

.PHONY: NCURSE
NCURSE: $(NCURSE_OBJ) $(SHARED_OBJ)
	$(CXX) -o $(NCURSE_NAME) $(NCURSE_OBJ) $(SHARED_OBJ) $(NCURSE_LIB) -shared

#CLEAN RULES

.PHONY: clean
clean:
	$(RM) $(SFML_OBJ) $(SDL_OBJ) $(NCURSE_OBJ) $(SHARED_OBJ)

.PHONY: fclean
fclean: clean
	$(RM) $(SFML_NAME) $(SDL_NAME) $(NCURSE_NAME)

.PHONY: re
re: fclean all

#DEBUG RULE

.PHONY: debug
debug: CPPFLAGS += -g3 -ggdb
debug: re
