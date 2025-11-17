CPP = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	RPN.cpp

HEADERS = RPN.hpp

OBJ = $(SRC:.cpp=.o)

all: RPN

RPN: $(OBJ) $(HEADERS)
	$(CPP)  $(OBJ) -o RPN

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f RPN

re: fclean all

.SECONDARY:

.PHONY: all fclean clean re