CPP = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	 Serializer.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

all: Convert

Convert: $(OBJ)
	$(CPP)  $(OBJ) -o Convert

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f Convert

re: fclean all

.SECONDARY:

.PHONY: all fclean clean re