CPP = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	 main.cpp

HEADERS = easyfind.hpp


OBJ = $(SRC:.cpp=.o)

all: easyfind

easyfind: $(OBJ) $(HEADERS)
	$(CPP)  $(OBJ) -o easyfind

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f easyfind

re: fclean all

.SECONDARY:

.PHONY: all fclean clean re