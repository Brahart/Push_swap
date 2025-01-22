/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:55:16 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/22 19:53:07 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../src/libft/include/libft.h"
# include "../src/libft/include/ft_printf.h"
# include "../src/libft/include/get_next_line.h"

typedef struct s_index
{
	int	stack;
	int	i;
}	t_index;

typedef struct s_stack
{
	int				value;
	struct s_stack	*prev;
	struct s_stack	*next;
	t_index			index;
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
void	rotate_a(t_stack **stack_a);
void	rotate_b(t_stack **stack_b);

/* ---------REVERSE-------- */
void	reverse_rotate_a(t_stack **stack_a);
void	reverse_rotate_b(t_stack **stack_b);

/* ---------------SOURCE-------------- */
t_stack	*add_new_node(int value);
t_stack	*add_back(t_stack *head, int value);
void	display_list(t_stack *head, const char *str);
void	free_list(t_stack *head);
void	add_to_list(t_stack **head, int value);
int		check_atol(char *nbr, t_stack *list);
int		check_is_sorted(t_stack **stack);
int		stack_size(t_stack **stack);

/* --------PARSING-------- */
int	check_double(t_stack **stack);

/* ----------ALGO--------- */
void	algo_sort(t_stack **stack_a);

/* ---------UTILS--------- */
void	ft_error(const char *str);
char	**check_arg(char *str);
void	free_split(char **split);

#endif
