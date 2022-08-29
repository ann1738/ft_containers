NAME = main
SRC = main.cpp
OBJ = $(SRC:%.cpp=%.o)
CXX = c++
CPPFLAGS = -Wall -Werror -Wextra -c -std=c++98 -g

all: $(NAME)

$(NAME):$(OBJ)
	$(CXX) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all ./main 2002

sanitize: re
	clang++ $(OBJ) -o $(NAME) -g -fsanitize=address
	clear

.PHONY: all clean fclean re sanitize valgrind