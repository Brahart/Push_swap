BOLD_GREEN	=	\e[1;32m
BOLD_RED	=	\e[1;31m
BOLD_BLUE	=	\e[1;34m
BOLD_YELLOW	=	\e[1;33m
PURPLE		=	\e[1;35m
BOLD_CYAN	=	\e[1;36m
STOP_COLOR	=	\e[0m

NAME		=	push_swap
BONUS		=	checker

CC			=	cc
FLAGS		=	-Wall -Wextra -Werror -g3

HEAD		=	include/push_swap.h

LIBFT_DIR 	=	src/libft/src/
LIB_LIBFT 	=	$(LIBFT_DIR)libft.a
LIBFT_FLAGS	=	-L$(LIBFT_DIR) $(LIB_LIBFT)

SRC_DIR 	= src/

SRC_2		=	src/content/main.c

BONUS_FILE	=	src/checker_bonus.c \

SRC_1 	=		src/algo/algorithm.c \
				src/algo/find_position_in_stack.c \
				src/algo/make_move_both.c \
				src/algo/make_move_simple.c \
				src/algo/sort_a.c \
				src/algo/step.c \
				src/content/check_sort.c \
				src/content/create_list.c \
				src/content/parsing.c \
				src/content/stack_utils.c \
				src/content/utils.c \
				src/move/push.c \
				src/move/reverse.c \
				src/move/rotate.c \
				src/move/swap.c

OBJ_1		=	$(SRC_1:%.c=%.o)
OBJ_2		=	$(SRC_2:%.c=%.o)
OBJ_BONUS	=	$(BONUS_FILE:.c=.o)

all: $(NAME)

%.o: $(SRC_DIR)%.c $(HEAD)
	@echo "$(PURPLE)"
	@$(CC) $(FLAGS) -c $< -o $@

bonus: $(BONUS)

$(BONUS): $(OBJ_1) $(OBJ_BONUS)
	@echo "$(BOLD_BLUE)Compilling Libft...$(STOP_COLOR)"
	make -sC $(LIBFT_DIR)
	@echo "$(BOLD_GREEN)SUCCESS !!!$(STOP_COLOR)"
	@echo "$(BOLD_BLUE)Creating executable $(BONUS)...$(PURPLE)"
	$(CC) $(FLAGS) $(OBJ_1) $(OBJ_BONUS) $(LIBFT_FLAGS) -o $(BONUS)
	@echo "$(BOLD_GREEN)SUCCESS !!!$(STOP_COLOR)"

$(NAME): $(OBJ_1) $(OBJ_2)
	@echo "$(BOLD_BLUE)Compilling Libft...$(STOP_COLOR)"
	make -sC $(LIBFT_DIR)
	@echo "$(BOLD_GREEN)SUCCESS !!!$(STOP_COLOR)"
	@echo "$(BOLD_BLUE)Creating executable $(NAME)...$(PURPLE)"
	$(CC) $(FLAGS) $(OBJ_1) $(OBJ_2) $(LIBFT_FLAGS) -o $(NAME)
	@echo "$(BOLD_GREEN)SUCCESS !!!$(STOP_COLOR)"

clean:
	@echo "$(BOLD_BLUE)Delete obj...$(STOP_COLOR)"
	@make clean -sC $(LIBFT_DIR)
	@rm -f $(OBJ_1) $(OBJ_2) $(OBJ_BONUS)
	@echo "$(BOLD_RED)SUCCESS !!!$(STOP_COLOR)"

fclean: clean
	@echo "$(BOLD_BLUE)Make fclean...$(STOP_COLOR)"
	@rm -f $(LIB_LIBFT) $(NAME) $(BONUS)
	@echo "$(BOLD_RED)SUCCESS !!!$(STOP_COLOR)"

re: fclean all

.PHONY: all clean fclean re bonus
