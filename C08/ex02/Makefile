CPP = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	 main.cpp 

HEADERS = MutantStack.hpp

OBJ = $(SRC:.cpp=.o)

all: MutantStack

MutantStack: $(OBJ) $(HEADERS)
	$(CPP)  $(OBJ) -o MutantStack

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f MutantStack

re: fclean all

.SECONDARY:

.PHONY: all fclean clean re