NAME = main
VECTOR_TESTS = vector_tests/element_access.cpp vector_tests/capacity.cpp vector_tests/modifiers.cpp

SRC = main.cpp tests/vector_tests.cpp tests/map_tests.cpp tests/stack_tests.cpp
OBJ = $(SRC:%.cpp=%.o)
CXX = c++
CPPFLAGS = -Wall -Werror -Wextra -c -std=c++98 -g

LOG_DIR = logs
DIFF_DIR = diff

OUTPUT_VECTOR_FT = $(LOG_DIR)/ft_vec.log
OUTPUT_MAP_FT = $(LOG_DIR)/ft_map.log
OUTPUT_STACK_FT = $(LOG_DIR)/ft_stk.log
OUTPUT_SET_FT = $(LOG_DIR)/ft_set.log

OUTPUT_VECTOR_STD = $(LOG_DIR)/std_vec.log
OUTPUT_MAP_STD = $(LOG_DIR)/std_map.log
OUTPUT_STACK_STD = $(LOG_DIR)/std_stk.log
OUTPUT_SET_STD = $(LOG_DIR)/std_set.log

OUTPUT_VECTOR_CMP = $(DIFF_DIR)/cmp_vec.diff
OUTPUT_MAP_CMP = $(DIFF_DIR)/cmp_map.diff
OUTPUT_STACK_CMP = $(DIFF_DIR)/cmp_stk.diff
OUTPUT_SET_CMP = $(DIFF_DIR)/cmp_set.diff

all: $(NAME)

$(NAME):$(OBJ)
	$(CXX) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean clear
	rm -f $(NAME)

re: fclean all

std: change_flag clean all

change_flag:
	$(eval CPPFLAGS += -D TESTING)

vector: $(LOG_DIR) $(DIFF_DIR)
	$(MAKE) ft_vector
	$(MAKE) std_vector
	@diff $(OUTPUT_VECTOR_FT) $(OUTPUT_VECTOR_STD) > $(OUTPUT_VECTOR_CMP) || exit 0
	cat $(OUTPUT_VECTOR_CMP)

ft_vector: clean all
	./$(NAME) vector > $(OUTPUT_VECTOR_FT)

std_vector: std
	./$(NAME) vector > $(OUTPUT_VECTOR_STD)

map: $(LOG_DIR) $(DIFF_DIR)
	$(MAKE) ft_map
	$(MAKE) std_map
	@diff $(OUTPUT_MAP_FT) $(OUTPUT_MAP_STD) > $(OUTPUT_MAP_CMP) || exit 0
	cat $(OUTPUT_MAP_CMP)

ft_map:  clean all
	./$(NAME) map > $(OUTPUT_MAP_FT)

std_map: std
	./$(NAME) map > $(OUTPUT_MAP_STD)

stack: $(LOG_DIR) $(DIFF_DIR)
	$(MAKE) ft_stack
	$(MAKE) std_stack
	@diff $(OUTPUT_STACK_FT) $(OUTPUT_STACK_STD) > $(OUTPUT_STACK_CMP) || exit 0
	cat $(OUTPUT_STACK_CMP)

ft_stack:  clean all
	./$(NAME) stack > $(OUTPUT_STACK_FT)

std_stack: std
	./$(NAME) stack > $(OUTPUT_STACK_STD)

set: $(LOG_DIR) $(DIFF_DIR)
	$(MAKE) ft_set
	$(MAKE) std_set
	@diff $(OUTPUT_SET_FT) $(OUTPUT_SET_STD) > $(OUTPUT_SET_CMP) || exit 0

ft_set:  clean all
	./$(NAME) set > $(OUTPUT_SET_FT)

std_set: std
	./$(NAME) set > $(OUTPUT_SET_STD)

test_all:
	$(MAKE) vector
	$(MAKE) map
	$(MAKE) stack
	$(MAKE) set

$(DIFF_DIR):
	mkdir $(DIFF_DIR)

$(LOG_DIR):
	mkdir $(LOG_DIR)

clear:
	rm -rf $(LOG_DIR) $(DIFF_DIR)

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all ./main test_all

sanitize: re
	clang++ $(OBJ) -o $(NAME) -g -fsanitize=address
	clear

.PHONY: all clean fclean re sanitize valgrind clear vector map stack set