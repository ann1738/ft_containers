NAME = main
VECTOR_TESTS = vector_tests/element_access.cpp vector_tests/capacity.cpp vector_tests/modifiers.cpp

SRC = main.cpp #tests/vector_tests.cpp #tests/stack_tests.cpp #tests/map_tests #$(VECTOR_TESTS)
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
	valgrind --leak-check=full --show-leak-kinds=all ./main

sanitize: re
	clang++ $(OBJ) -o $(NAME) -g -fsanitize=address
	clear
	./$(NAME)
.PHONY: all clean fclean re