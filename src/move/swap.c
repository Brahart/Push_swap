/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:55:26 by asinsard          #+#    #+#             */
/*   Updated: 2025/02/07 20:03:24 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	swap_a(t_stack **stack_a)
{
	int	tmp;

	tmp = 0;
	if ((*stack_a) && (*stack_a)->next)
	{
		tmp = (*stack_a)->content;
		(*stack_a)->content = (*stack_a)->next->content;
		(*stack_a)->next->content = tmp;
	}
	ft_printf("sa\n");
}

void	swap_b(t_stack **stack_b)
{
	int	tmp;

	if ((*stack_b) && (*stack_b)->next)
	{
		tmp = (*stack_b)->content;
		(*stack_b)->content = (*stack_b)->next->content;
		(*stack_b)->next->content = tmp;
	}
	ft_printf("sb\n");
}

void	swap_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
	ft_printf("ss\n");
}
