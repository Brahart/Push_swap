/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:26:53 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/24 03:07:26 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_three(t_stack **stack)
{
	if (stack_max((*stack)) == (*stack)->value)
	{
		rotate_a(stack);
		if (stack_min((*stack)) == (*stack)->next->value)
			swap_a(stack);
	}
	else if (stack_min(*stack) == (*stack)->value)
	{
		swap_a(stack);
		rotate_a(stack);
	}
	else if (stack_min(*stack) == (*stack)->next->value)
		swap_a(stack);
	else
		reverse_rotate_a(stack);
	int	i;
	i = stack_last((*stack));
}

void	algo_sort(t_stack **stack_a)
{
	int		len;
	t_stack	*stack_b;

	stack_b = NULL;
	len = stack_size(*stack_a);
	if (len == 3 && !check_is_sorted(stack_a))
		sort_three(stack_a);
	else if (len > 3 && !check_is_sorted(stack_a))
		push_to_b(stack_a, &stack_b);
	else if (len > 3 && !check_is_sorted(stack_a))
		push_to_b(stack_a, &stack_b);
	else if (len == 3 && !check_is_sorted(stack_a))
		sort_three(stack_a);
}
