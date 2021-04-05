##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC	=	Core.cpp

OBJ	=	$(SRC:.cpp=.o)

###############################################################################

NAME	=	arcade_core.so

CXXFLAGS	=	-Wall -Wextra -fPIC

CPPFLAGS	=	-iquote./ -iquote../

CXX	=	g++
################################################################################

#MAIN RULES
all: $(NAME)

$(NAME):	$(OBJ)
	$(CXX) -o $(NAME) $(OBJ) -shared

################################################################################

#CLEAN RULES
clean:
	$(RM) $(OBJ) *.gcda *.gcno

fclean:	clean
	$(RM) $(NAME) unit_tests

re:	fclean all

debug:	CPPFLAGS += -g3 -ggdb
debug:	re

.PHONY: all fclean re clean $(NAME) debug tests_run