##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC	=\
		src/main.cpp						\
		src/dynamicFile.cpp					\
		src/Error/Error.cpp					\
		src/LoadLib/LoadLib.cpp				\
		src/InterfaceGame/Iinterface.cpp	\
		src/Core/Core.cpp					\
		src/Graphic/ADisplayModule.cpp		\

OBJ	=	$(SRC:.cpp=.o)

###############################################################################

NAME	=	arcade

CXXFLAGS	=	-Wall -Wextra -std=c++17

CPPFLAGS	=	-iquote./src/

CXX	=	g++

#MAIN RULES
all: $(NAME) games graphical

$(NAME):	$(OBJ)
	$(CXX) -o $(NAME) $(OBJ) -ldl -lncurses

################################################################################

#GAME RULES

.PHONY: games
games:
	make -C ./src/Game

.PHONY: graphical
graphical:
	make -C ./src/Graphic

################################################################################

#CLEAN RULES
clean:
	$(RM) $(OBJ) *.gcda *.gcno
	make clean -C ./src/Game
	make clean -C ./src/Graphic

fclean:	clean
	$(RM) $(NAME) unit_tests
	make fclean -C ./src/Game
	make fclean -C ./src/Graphic

re:		fclean all
re:
	make re -C src/Graphic
	make re -C src/Game

debug:	CPPFLAGS += -g3 -ggdb
debug:	re
	make debug -C ./src/Game
	make debug -C ./src/Graphic

.PHONY: all fclean re clean $(NAME) debug
