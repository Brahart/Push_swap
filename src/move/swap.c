/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrahamsinsard <abrahamsinsard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:55:26 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/24 15:05:20 by abrahamsins      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	swap_a(t_stack **stack_a)
{
	int	tmp;

	if ((*stack_a)->value && (*stack_a)->next->value)
	{
		tmp = (*stack_a)->value;
		(*stack_a)->value = (*stack_a)->next->value;
		(*stack_a)->next->value = tmp;
	}
	ft_printf("sa\n");
}

void	swap_b(t_stack **stack_b)
{
	int	tmp;

	if ((*stack_b)->value && (*stack_b)->next->value)
	{
		tmp = (*stack_b)->value;
		(*stack_b)->value = (*stack_b)->next->value;
		(*stack_b)->next->value = tmp;
	}
	ft_printf("sb\n");
}

void	swap_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
	ft_printf("ss\n");
}
