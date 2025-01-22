/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:09:22 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/21 19:39:48 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rotate_a(t_pile **pile_a)
{
	if (!pile_a || !(*pile_a) || (*pile_a)->next == *pile_a)
		return ;
	(*pile_a) = (*pile_a)->next;
	ft_printf("ra\n");
}

void	rotate_b(t_pile **pile_b)
{
	if (!pile_b || !(*pile_b) || (*pile_b)->next == *pile_b)
		return ;
	(*pile_b) = (*pile_b)->next;
	ft_printf("rb\n");
}

void	rotate_rr(t_pile **pile_a, t_pile **pile_b)
{
	rotate_a(pile_a);
	rotate_b(pile_b);
}
