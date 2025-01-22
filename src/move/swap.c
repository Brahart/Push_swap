/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:55:26 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/21 17:59:40 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	swap_a(t_pile **pile_a)
{
	int	tmp;
	
	if ((*pile_a)->value && (*pile_a)->next->value)
	{
		tmp = (*pile_a)->value;
		(*pile_a)->value = (*pile_a)->next->value;
		(*pile_a)->next->value = tmp;
	}
	ft_printf("sa\n");
}

void	swap_b(t_pile **pile_b)
{
	int	tmp;

	if ((*pile_b)->value && (*pile_b)->next->value)
	{
		tmp = (*pile_b)->value;
		(*pile_b)->value = (*pile_b)->next->value;
		(*pile_b)->next->value = tmp;
	}
	ft_printf("sb\n");
}

void	swap_ss(t_pile **pile_a, t_pile **pile_b)
{
	swap_a(pile_a);
	swap_b(pile_b);
}
