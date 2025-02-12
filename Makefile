BOLD_GREEN	= \e[1;32m
BOLD_RED	= \e[1;31m
BOLD_BLUE	= \e[1;34m
STOP_COLOR	= \e[0m

NAME		= push_swap

CC			= cc
FLAGS		= -Wall -Wextra -Werror -g3

HEAD		= include/push_swap.h

LIBFT_DIR 	= src/libft/src/
LIB_LIBFT 	= $(LIBFT_DIR)libft.a
LIBFT_FLAGS	= -L$(LIBFT_DIR) $(LIB_LIBFT)

SRC_DIR 	= src/
SRC_FILE 	=	algo/algorithm.c \
				algo/find_position_in_b.c \
				algo/make_move_both.c \
				algo/make_move_simple.c \
				algo/parsing.c \
				algo/sort_a.c \
				algo/step.c \
				content/atoi.c \
				content/check_sort.c \
				content/create_list.c \
				content/main.c \
				content/stack_find_nbr.c \
				content/stack_utils.c \
				content/utils.c \
				move/push.c \
				move/reverse.c \
				move/rotate.c \
				move/swap.c

SRC 		= $(addprefix $(SRC_DIR), $(SRC_FILE))

OBJ			= $(SRC:%.c=%.o)

all: $(NAME)

%.o: $(SRC_DIR)%.c $(HEAD)
	@$(CC) $(FLAGS) -c $< -o $@


$(NAME): $(OBJ)
	@echo "$(BOLD_BLUE)Compilling Libft...$(STOP_COLOR)"
	make -sC $(LIBFT_DIR)
	@echo "$(BOLD_GREEN)SUCCESS !!!$(STOP_COLOR)"
	@echo "$(BOLD_BLUE)Creating executable $(NAME)...$(STOP_COLOR)"
	$(CC) $(FLAGS) $(OBJ) $(LIBFT_FLAGS) -o $(NAME)
	@echo "$(BOLD_GREEN)SUCCESS !!!$(STOP_COLOR)"

clean:
	@echo "$(BOLD_BLUE)Delete obj...$(STOP_COLOR)"
	make clean -sC $(LIBFT_DIR)
	rm -f $(OBJ)
	@echo "$(BOLD_RED)SUCCESS !!!$(STOP_COLOR)"

fclean: clean
	@echo "$(BOLD_BLUE)Make fclean...$(STOP_COLOR)"
	rm -f $(LIB_LIBFT) $(NAME)
	@echo "$(BOLD_RED)SUCCESS !!!$(STOP_COLOR)"

re: fclean all

.PHONY: all clean fclean re


