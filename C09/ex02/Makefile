CPP = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	PmergeMe.cpp

HEADERS = PmergeMe.hpp

OBJ = $(SRC:.cpp=.o)

all: PmergeMe

PmergeMe: $(OBJ) $(HEADERS)
	$(CPP)  $(OBJ) -o PmergeMe

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f PmergeMe

re: fclean all

.SECONDARY:

.PHONY: all fclean clean re