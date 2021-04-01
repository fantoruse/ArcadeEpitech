##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

#NIBBLER SOURCES

NIBBLER_SRC =	AGame.cpp		\
				Nibbler/Nibbler.cpp

NIBBLER_OBJ = $(NIBBLER_SRC:.cpp=.o)

NIBBLER_NAME	=	arcade_nibbler.so

NIBBLER_LIB	=

#################################################################################

#VAR

CXX	=	g++

CPPFLAGS	=	-iquote./ -iquote..

CXXFLAGS	=	-Wall -Wextra -fPIC -shared

#################################################################################

#RULES

.PHONY: all
all: nibbler

#MAIN RULES

.PHONY: nibbler
nibbler: $(NIBBLER_OBJ)
	$(CXX) -o $(NIBBLER_NAME) $(NIBBLER_OBJ) $(NIBBLER_LIB)

#CLEAN RULES

.PHONY: clean
clean:
	$(RM) $(NIBBLER_OBJ)

.PHONY: fclean
fclean: clean
	$(RM) $(NIBBLER_NAME)

.PHONY: re
re: fclean all

#DEBUG RULE

.PHONY: debug
debug: CPPFLAGS += -g3 -ggdb
debug: re
