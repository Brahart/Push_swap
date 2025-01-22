/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:55:22 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/21 19:38:53 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	reverse_rotate_a(t_pile **pile_a)
{
	if (!pile_a || !(*pile_a) || (*pile_a)->next == *pile_a)
		return ;
	(*pile_a) = (*pile_a)->prev;
	ft_printf("ra\n");
}

void	reverse_rotate_b(t_pile **pile_b)
{
	if (!pile_b || !(*pile_b) || (*pile_b)->next == *pile_b)
		return ;
	(*pile_b) = (*pile_b)->prev;
	ft_printf("rb\n");
}

void	reverse_rotate_rr(t_pile **pile_a, t_pile **pile_b)
{
	reverse_rotate_a(pile_a);
	reverse_rotate_b(pile_b);
}
