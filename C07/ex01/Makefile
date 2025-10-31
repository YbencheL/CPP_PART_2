CPP = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp

HEADERS = Iter.hpp

OBJ = $(SRC:.cpp=.o)

all: iter

iter: $(OBJ)
	$(CPP)  $(OBJ) -o iter

%.o: %.cpp $(HEADERS)
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f iter

re: fclean all

.SECONDARY:

.PHONY: all fclean clean re