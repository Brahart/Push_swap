/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:55:16 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/22 01:48:55 by asinsard         ###   ########lyon.fr   */
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

typedef struct s_pile
{
	int				value;
	struct s_pile	*prev;
	struct s_pile	*next;
	t_index			index;
}	t_pile;


/* ---------------MOVE-------------- */
/* ----------SWAP---------- */
void	swap_a(t_pile **pile_a);
void	swap_b(t_pile **pile_b);
void	swap_ss(t_pile **pile_a, t_pile **pile_b);

/* ----------PUSH---------- */
void	push_to_a(t_pile **pile_a, t_pile **pile_b);
void	push_to_b(t_pile **pile_a, t_pile **pile_b);

/* ---------ROTATE--------- */
void	rotate_a(t_pile **pile_a);
void	rotate_b(t_pile **pile_b);

/* ---------REVERSE-------- */
void	reverse_rotate_a(t_pile **pile_a);
void	reverse_rotate_b(t_pile **pile_b);

/* ---------------SOURCE-------------- */
t_pile	*add_new_node(int value);
t_pile	*add_back(t_pile *head, int value);
void	display_list(t_pile *head, const char *str);
void	free_list(t_pile *head);
void	add_to_list(t_pile **head, int value);
int	check_atol(char *nbr, t_pile *list);

/* ---------UTILS--------- */
void	ft_error(const char *str);
char	**check_arg(char *str);
void	free_split(char **split);

#endif
