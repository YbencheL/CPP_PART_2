CPP = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	 main.cpp Span.cpp

HEADERS = Span.hpp


OBJ = $(SRC:.cpp=.o)

all: Span

Span: $(OBJ) $(HEADERS)
	$(CPP)  $(OBJ) -o Span

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f Span

re: fclean all

.SECONDARY:

.PHONY: all fclean clean re