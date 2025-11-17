CPP = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	BitcoinExchange.cpp Date.cpp

HEADERS = Date.hpp

OBJ = $(SRC:.cpp=.o)

all: btc

btc: $(OBJ) $(HEADERS)
	$(CPP)  $(OBJ) -o btc

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f btc

re: fclean all

.SECONDARY:

.PHONY: all fclean clean re