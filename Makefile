##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC	=	src/main.cpp				\
		src/dynamicFile.cpp			\
		src/Error/Error.cpp				\
		src/LoadLib/LoadLib.cpp			\
		src/InterfaceGame/Iinterface.cpp	\
		##src/Graphic/SFML/SfmlModule.cpp 	\
		##src/Graphic/ADisplayModule.cpp
		##src/LoadLib/LoadLib.cpp			\

SRC_TESTS   =   tests/component/Chipsets/Gates/testsAnd.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	arcade

CXXFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-iquote./src/

CXX	=	g++

all: $(NAME)

$(NAME):	$(OBJ)
	$(CXX) -o $(NAME) $(OBJ) -ldl

clean:
	$(RM) $(OBJ) *.gcda *.gcno unit_tests

fclean:	clean
	$(RM) $(NAME) unit_tests

re:	fclean all $(NAME)

debug:	CPPFLAGS += -g3 -ggdb
debug:	re

tests_run: SRC += $(SRC_TESTS)
tests_run: LDFLAGS += -lcriterion --coverage
tests_run: CPPFLAGS += -iquote./tests/ -DTU
tests_run: CXXFLAGS := $(filter-out -Werror, $(CXXFLAGS))
tests_run: SRC := $(filter-out src/main.cpp, $(SRC))
tests_run: NAME := unit_tests
tests_run:
	$(CXX) -o $(NAME) $(SRC) $(LDFLAGS) $(CPPFLAGS)
	./$(NAME)

.PHONY: all fclean re clean $(NAME) debug tests_run