CPP = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	main.cpp Bureaucrat.cpp

OBJ = $(SRC:.cpp=.o)

all: bureaucrat

bureaucrat: $(OBJ)
	$(CPP)  $(OBJ) -o bureaucrat

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f bureaucrat

re: fclean all

.SECONDARY:

.PHONY: all fclean clean re