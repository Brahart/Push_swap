/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:55:16 by asinsard          #+#    #+#             */
/*   Updated: 2025/02/14 01:45:07 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	struct s_stack	*prev;
	struct s_stack	*next;
	int				content;
	int				step;
	int				pos_in_b;
	int				min;
	int				max;
}	t_stack;

/* ---------------MOVE-------------- */
/* ----------SWAP---------- */
void	swap_a(t_stack **stack_a, bool flag);
void	swap_b(t_stack **stack_b, bool flag);
void	swap_ss(t_stack **stack_a, t_stack **stack_b, bool flag);

/* ----------PUSH---------- */
void	push_to_a(t_stack **stack_a, t_stack **stack_b, bool flag);
void	push_to_b(t_stack **stack_a, t_stack **stack_b, bool flag);

/* ---------ROTATE--------- */
void	rotate_a(t_stack **stack_a, bool flag);
void	rotate_b(t_stack **stack_b, bool flag);
void	rotate_rr(t_stack **stack_a, t_stack **stack_b, bool flag);

/* ---------REVERSE-------- */
void	reverse_rotate_a(t_stack **stack_a, bool flag);
void	reverse_rotate_b(t_stack **stack_b, bool flag);
void	reverse_rotate_rr(t_stack **stack_a, t_stack **stack_b, bool flag);

/* ---------------SOURCE-------------- */
/* --------PARSING-------- */
int		check_double(t_stack *stack);
int		check_atol(char *nbr, t_stack *list, int ac, char **arg);
char	**create_stack(int ac, char **av, t_stack **a);
void	check_error(char **arg, int ac, t_stack *a);

/* ----------ALGO--------- */
void	algo_sort(t_stack **stack_a);

/* -------ALGO_UTILS------ */
int		pos_value_in_b(t_stack *b, int value, bool flag);
void	alloc_step(t_stack **a, t_stack **b);
int		find_best_step(t_stack **a);
void	comp_move(t_stack **tmp, int cost_a, int cost_b);
void	comp_rev_rot(t_stack **tmp, int cost_a, int cost_b);
void	comp_rot(t_stack **tmp, int cost_a, int cost_b);
void	find_move_together(t_stack **a, t_stack **b, int best);
void	make_rotate(t_stack **stack, int rot, int move);
void	make_reverse_rotate(t_stack **stack, int rev_rot, int move);
void	make_move_simple(t_stack **a, t_stack **b, int best);
void	find_min_and_move(t_stack **a);
void	find_random_and_move(t_stack **a, t_stack **b);
void	find_good_place(t_stack **a);
int		r_or_rr(int *cost_a, int *cost_b, t_stack *a, t_stack *b);
int		check_is_sorted(t_stack *stack);

/* ------STACK_UTILS------ */
t_stack	*add_new_node(int value);
t_stack	*add_back(t_stack *head, int value);
void	display_list(t_stack *head, const char *str);
void	free_stack(t_stack *head);
void	add_to_list(t_stack **head, int value);
int		stack_min(t_stack *stack);
int		stack_max(t_stack *stack);
int		stack_size(t_stack *stack);
int		stack_last(t_stack *stack);

/* ---------UTILS--------- */
void	ft_free(int ac, t_stack *a, char **arg, bool flag);
void	ft_error(const char *str);
char	**check_arg(char *str);
void	free_split(char **split);
int		find_nbr_rotate(t_stack *stack, int value, bool flag);

#endif
