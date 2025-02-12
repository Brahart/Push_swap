/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrahamsinsard <abrahamsinsard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:55:16 by asinsard          #+#    #+#             */
/*   Updated: 2025/02/12 15:37:57 by abrahamsins      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "../src/libft/include/libft.h"
# include "../src/libft/include/ft_printf.h"
# include "../src/libft/include/get_next_line.h"

typedef struct s_stack
{
	struct s_stack	*prev;
	struct s_stack	*next;
	int				content;
	int				step;
	int				pos_in_b;
}	t_stack;


/* ---------------MOVE-------------- */
/* ----------SWAP---------- */
void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	swap_ss(t_stack **stack_a, t_stack **stack_b);

/* ----------PUSH---------- */
void	push_to_a(t_stack **stack_a, t_stack **stack_b);
void	push_to_b(t_stack **stack_a, t_stack **stack_b);

/* ---------ROTATE--------- */
void	rotate_a(t_stack **stack_a, bool flag);
void	rotate_b(t_stack **stack_b, bool flag);
void	rotate_rr(t_stack **stack_a, t_stack **stack_b);

/* ---------REVERSE-------- */
void	reverse_rotate_a(t_stack **stack_a, bool flag);
void	reverse_rotate_b(t_stack **stack_b, bool flag);
void	reverse_rotate_rr(t_stack **stack_a, t_stack **stack_b);

/* ---------------SOURCE-------------- */
t_stack	*add_new_node(int value);
t_stack	*add_back(t_stack *head, int value);
void	display_list(t_stack *head, const char *str);
void	free_list(t_stack *head);
void	add_to_list(t_stack **head, int value);
int		check_atol(char *nbr, t_stack *list);
int		check_is_sorted(t_stack *stack);

/* --------PARSING-------- */
int		check_double(t_stack **stack);

/* ----------ALGO--------- */
void	algo_sort(t_stack **stack_a);
void	sort_three(t_stack **stack);

/* ------STACK_UTILS------ */
int		stack_min(t_stack *stack);
int		stack_max(t_stack *stack);
int		stack_size(t_stack *stack);
int		stack_last(t_stack *stack);

/* ---------UTILS--------- */
void	ft_error(const char *str);
char	**check_arg(char *str);
void	free_split(char **split);
int		find_nbr_rotate(t_stack *stack, int value, bool flag);

int		pos_value_in_b(t_stack *b, int value, bool flag);
void	alloc_step(t_stack **a, t_stack **b);
int		find_best_step(t_stack **a);
void	comp_move(t_stack **tmp, int cost_a, int cost_b);
void	comp_rev_rot(t_stack **tmp, int cost_a, int cost_b);
void	comp_rot(t_stack **tmp, int cost_a, int cost_b);
void	find_move_together(t_stack **a, t_stack **b, int best);
void	make_rotate(t_stack **stack, int rot, int move);
void	make_reverse_rotate(t_stack **stack, int rev_rot, int move);
void	make_move_simple(t_stack **a, t_stack **b, int cost_a, int cost_b);
void	find_min_and_move(t_stack **a, t_stack **b);
void	find_random_and_move(t_stack **a, t_stack **b);
void	find_good_place(t_stack **a);
int		r_or_rr(int *cost_a, int *cost_b, t_stack *a, t_stack *b);
#endif
