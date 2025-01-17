/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:55:16 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/17 16:36:01 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../src/libft/include/libft.h"
# include "../src/libft/include/ft_printf.h"
# include "../src/libft/include/get_next_line.h"

typedef struct s_pile
{
	int				value;
	struct s_pile	*prev;
	struct s_pile	*next;
}	t_pile;


/* ---------------MOVE-------------- */
/* ----------SWAP---------- */
void	swap_a(t_pile **pile_a);
void	swap_b(t_pile **pile_b);
void	swap_ss(t_pile **pile_a, t_pile **pile_b);

/* ---------------SOURCE-------------- */
t_pile	*add_new_node(int value);
t_pile	*add_back(t_pile *head, int value);
void	display_list(t_pile *head);
void	free_list(t_pile *head);

#endif
