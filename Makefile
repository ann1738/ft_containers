NAME = main
VECTOR_TESTS = vector_tests/element_access.cpp vector_tests/capacity.cpp vector_tests/modifiers.cpp

SRC = main.cpp tests/vector_tests.cpp tests/map_tests.cpp #tests/stack_tests.cpp
OBJ = $(SRC:%.cpp=%.o)
CXX = c++
CPPFLAGS = -Wall -Werror -Wextra -c -std=c++98 -g

OUTPUT_VECTOR_FT = ft_vec.log
OUTPUT_MAP_FT = ft_map.log
OUTPUT_STACK_FT = ft_stk.log
OUTPUT_SET_FT = ft_set.log

OUTPUT_VECTOR_STD = std_vec.log
OUTPUT_MAP_STD = std_map.log
OUTPUT_STACK_STD = std_stk.log
OUTPUT_SET_STD = std_set.log

OUTPUT_VECTOR_CMP = cmp_vec.diff
OUTPUT_MAP_CMP = cmp_map.diff
OUTPUT_STACK_CMP = cmp_stk.diff
OUTPUT_SET_CMP = cmp_set.diff

all: $(NAME)

$(NAME):$(OBJ)
	$(CXX) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

std: change_flag re

change_flag:
	$(eval CPPFLAGS += -D TESTING)

vector:
	$(MAKE) ft_vector
	$(MAKE) std_vector
	@diff $(OUTPUT_VECTOR_FT) $(OUTPUT_VECTOR_STD) > $(OUTPUT_VECTOR_CMP) || exit 0
	cat $(OUTPUT_VECTOR_CMP)

ft_vector: re
	./$(NAME) vector > $(OUTPUT_VECTOR_FT)

std_vector: std
	./$(NAME) vector > $(OUTPUT_VECTOR_STD)

map:
	$(MAKE) ft_map
	$(MAKE) std_map
	@diff $(OUTPUT_MAP_FT) $(OUTPUT_MAP_STD) > $(OUTPUT_MAP_CMP) || exit 0
	cat $(OUTPUT_MAP_CMP)

ft_map: re
	./$(NAME) map > $(OUTPUT_MAP_FT)

std_map: std
	./$(NAME) map > $(OUTPUT_MAP_STD)

stack:
	$(MAKE) ft_stack
	$(MAKE) std_stack
	@diff $(OUTPUT_STACK_FT) $(OUTPUT_STACK_STD) > $(OUTPUT_STACK_CMP) || exit 0

ft_stack: re
	./$(NAME) stack > $(OUTPUT_STACK_FT)

std_stack: std
	./$(NAME) stack > $(OUTPUT_STACK_STD)

set:
	$(MAKE) ft_set
	$(MAKE) std_set
	@diff $(OUTPUT_SET_FT) $(OUTPUT_SET_STD) > $(OUTPUT_SET_CMP) || exit 0

ft_set: re
	./$(NAME) set > $(OUTPUT_SET_FT)

std_set: std
	./$(NAME) set > $(OUTPUT_SET_STD)

test_all:
	$(MAKE) vector
	$(MAKE) map
	$(MAKE) stack
	$(MAKE) set

clear:
	rm -f $(wildcard *.log) $(wildcard *.diff)

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all ./main

sanitize: re
	clang++ $(OBJ) -o $(NAME) -g -fsanitize=address
	clear
	./$(NAME) vector
.PHONY: all clean fclean re