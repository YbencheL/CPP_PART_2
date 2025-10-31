CPP = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp

HEADERS = Array.hpp

OBJ = $(SRC:.cpp=.o)

all: arr

arr: $(OBJ)
	$(CPP)  $(OBJ) -o arr

%.o: %.cpp $(HEADERS)
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f arr

re: fclean all

.SECONDARY:

.PHONY: all fclean clean re