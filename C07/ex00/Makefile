CPP = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	 main.cpp

OBJ = $(SRC:.cpp=.o)

all: whatever

whatever: $(OBJ)
	$(CPP)  $(OBJ) -o whatever

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f whatever

re: fclean all

.SECONDARY:

.PHONY: all fclean clean re