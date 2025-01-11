BOLD_GREEN	= \e[1;32m
BOLD_RED	= \e[1;31m
BOLD_BLUE	= \e[1;34m
STOP_COLOR	= \e[0m

EXEC		= push_swap

CC			= cc
FLAGS		= -Wall -Wextra -Werror -g

HEAD		= include/push_swap.h

LIBFT_DIR 	= src/libft/src/
LIB_LIBFT 	= $(LIBFT_DIR)libft.a
LIBFT_FLAGS	= -L$(LIBFT_DIR) $(LIB_LIBFT)

SRC_DIR 	= src/content/
#SRC_FILE =	main.c \
SRC = $(addprefix $(SRC_DIR), $(SRC_FILE))

MOVE_DIR	= src/move/
MOVE_FILE	= 	push.c \
				reverse.c \
				swap.c
MOVE		= $(addprefix $(MOVE_DIR), $(MOVE_FILE))

OBJ_MOVE	= $(MOVE:%.c=%.o)
OBJ_SRC		= $(SRC:%.c=%.o)

all: $(EXEC)

$(MOVE_DIR)%.o: %.c $(HEAD)
	@$(CC) $(FLAGS) -c $< -o $@

$(EXEC): $(OBJ_MOVE) $(OBJ_SRC)
#	@echo "$(BOLD_BLUE)Make Libft...$(STOP_COLOR)"
#	@make -sC $(LIBFT_DIR)
#	@echo "$(BOLD_GREEN)SUCCESS !!!$(STOP_COLOR)"
	@echo "$(BOLD_BLUE)Creating executable push_swap...$(STOP_COLOR)"
	@$(CC) $(FLAGS) $(OBJ_MOVE) $(OBJ_SRC) -o $(EXEC)
	@echo "$(BOLD_GREEN)SUCCESS !!!$(STOP_COLOR)"

clean:
	@echo "$(BOLD_BLUE)Delete obj...$(STOP_COLOR)"
#	@make clean -sC src/libft/src/
	@rm -f $(SRC_DIR)*.o
	@rm -f $(MOVE_DIR)*.o
	@echo "$(BOLD_RED)SUCCESS !!!$(STOP_COLOR)"

fclean: clean
	@echo "$(BOLD_BLUE)Make fclean...$(STOP_COLOR)"
	@rm -f $(LIB_LIBFT) $(EXEC)
	@echo "$(BOLD_RED)SUCCESS !!!$(STOP_COLOR)"

re: fclean all

.PHONY: all clean fclean re


