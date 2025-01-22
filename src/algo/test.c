/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:26:53 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/22 19:39:10 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_three(t_stack *stack)
{
	
}

void	algo_sort(t_stack **stack_a)
{
	int		len;
	t_stack	*stack_b;

	stack_b = NULL;
	len = stack_size(stack_a);
	// if (len == 3 && !check_is_sorted(stack_a))
	// 	sort_three(stack_a);
	while (len > 3 && !check_is_sorted(stack_a))
	{
		push_to_b(stack_a, &stack_b);
		len = stack_size(stack_a);
	}
	display_list((*stack_a), "stack_a");
	display_list(stack_b, "stack_b");
	free_list(stack_b);
}
