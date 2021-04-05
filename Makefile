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
		##src/Graphic/Ncurses/Ncurses.cpp 	\
		##src/Graphic/SFML/SfmlModule.cpp 	\

OBJ	=	$(SRC:.cpp=.o)

###############################################################################

NAME	=	arcade

CXXFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-iquote./src/

CXX	=	g++ -std=c++17

#MAIN RULES
all: $(NAME) #games core graphical

$(NAME):	$(OBJ)
	$(CXX) -o $(NAME) $(OBJ) -ldl -lncurses

################################################################################

#GAME RULES

.PHONY: games
games:
	make -C ./src/Game

.PHONY: core
core:
	make -C ./src/Core

.PHONY: graphical
graphical:
	make -C ./src/Graphic

################################################################################

#CLEAN RULES
clean:
	$(RM) $(OBJ) *.gcda *.gcno
	make clean -C ./src/Game
	make clean -C ./src/Core
	make clean -C ./src/Graphic

fclean:	clean
	$(RM) $(NAME) unit_tests
	make fclean -C ./src/Game
	make fclean -C ./src/Core
	make fclean -C ./src/Graphic

re:	fclean all

debug:	CPPFLAGS += -g3 -ggdb
debug:	re
	make debug -C ./src/Game
	make debug -C ./src/Core
	make debug -C ./src/Graphic

.PHONY: all fclean re clean $(NAME) debug