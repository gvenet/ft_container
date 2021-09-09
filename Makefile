SRC_DIR	:= srcs/
INC_DIR	:= inc/
OBJ_DIR	:= obj/
BIN_DIR	:= bin/
NAME	:= $(BIN_DIR)EX00

SRC		:= $(wildcard $(SRC_DIR)*.cpp) $(wildcard $(SRC_DIR)*/*.cpp)
OBJ		:= $(SRC:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)
INC		:= $(wildcard $(INC_DIR)*.hpp)
CC		:= clang++
CFLAGS	:= -Wall -Wextra -Werror -std=c++98

all: $(NAME)
	echo "$^ \033[32mrdy 2 use\033[0m"
	echo "--------------------------------------------"
	echo ""

$(NAME):  $(OBJ) | $(BIN_DIR)
	$(CC) $^ -o $@
	echo "$@ (exec) \033[32mcreated\033[0m"
	echo "--------------------------------------------"

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(INC)| $(OBJ_DIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
	echo "$@ \033[32mcreated\033[0m"

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@
	echo "$@ \033[32mdir created\033[0m"
	
clean:
	$(RM) -rf $(OBJ_DIR)
	echo "$(OBJ_DIR) \033[31mdir deleted\033[0m"

fclean:
	$(RM) -rf $(OBJ_DIR)
	echo "$(OBJ_DIR) \033[31mdir deleted\033[0m"
	$(RM) -rf $(BIN_DIR)
	echo "$(BIN_DIR) \033[31mdir deleted\033[0m"

fclean_re:
	$(RM) -rf $(OBJ_DIR)/*.o
	echo "$(OBJ_DIR)*.o \033[31mdir deleted\033[0m"
	$(RM) -rf $(BIN_DIR)
	echo "$(BIN_DIR) \033[31mdir deleted\033[0m"

re: fclean_re all

.PHONY: all clean fclean re
.SILENT: