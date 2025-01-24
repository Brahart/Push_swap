/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrahamsinsard <abrahamsinsard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:26:53 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/24 16:39:55 by abrahamsins      ###   ########lyon.fr   */
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

void	sort_until_three(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		i;

	while (stack_size((*stack_a)) > 3 && !check_is_sorted((*stack_a)))
	{
		tmp = (*stack_a);
		i = rotate_type_ab((*stack_a), (*stack_b));
		while (i >= 0)
		{
			if (i == calc_rarb_a((*stack_a), (*stack_b), tmp->value))
				i = move_rarb(stack_a, stack_b, tmp->value, 'a');
			else if (i == calc_rarrb_a((*stack_a), (*stack_b), tmp->value))
				i = move_rarrb(stack_a, stack_b, tmp->value, 'a');
			else if (i == calc_rrarb_a((*stack_a), (*stack_b), tmp->value))
				i = move_rrarb(stack_a, stack_b, tmp->value, 'a');
			else if (i == calc_rrarrb_a((*stack_a), (*stack_b), tmp->value))
				i = move_rrarrb(stack_a, stack_b, tmp->value, 'a');
			else
				tmp = tmp->next;
		}
	}
}

t_stack	**sort_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		i;

	while ((*stack_b))
	{
		tmp = *stack_b;
		i = rotate_type_ba((*stack_a), (*stack_b));
		while (i >= 0)
		{
			if (i == calc_rarb_a((*stack_a), (*stack_b), tmp->value))
				i = move_rarb(stack_a, stack_b, tmp->value, 'b');
			else if (i == calc_rarrb_a((*stack_a), (*stack_b), tmp->value))
				i = move_rarrb(stack_a, stack_b, tmp->value, 'b');
			else if (i == calc_rrarb_a((*stack_a), (*stack_b), tmp->value))
				i = move_rrarb(stack_a, stack_b, tmp->value, 'b');
			else if (i == calc_rrarrb_a((*stack_a), (*stack_b), tmp->value))
				i = move_rrarrb(stack_a, stack_b, tmp->value, 'b');
			else
				tmp = tmp->next;
		}
	}
	return (stack_a);
}

t_stack	*sort_b(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		len;

	stack_b = NULL;
	len = stack_size((*stack_a));
	if (len > 3 && !check_is_sorted((*stack_a)))
		push_to_b(stack_a, &stack_b);
	if (len > 3 && !check_is_sorted((*stack_a)))
		push_to_b(stack_a, &stack_b);
	if (len > 3 && !check_is_sorted((*stack_a)))
		sort_until_three(stack_a, &stack_b);
	if (!check_is_sorted((*stack_a)))
		sort_three(stack_a);
	return (stack_b);
		
}

void	algo_sort(t_stack **stack_a)
{
	int		len;
	int		i;
	t_stack	*stack_b;

	len = stack_size(*stack_a);
	stack_b = NULL;
	if (len == 2 && !check_is_sorted((*stack_a)))
		swap_a(stack_a);
	else
	{
		stack_b = sort_b(stack_a);
		stack_a = sort_a(stack_a, &stack_b);
		i = find_index((*stack_a), stack_min((*stack_a)));
		if (i < stack_size((*stack_a)) - i)
		{
			while ((*stack_a)->value != stack_min((*stack_a)))
				rotate_a(stack_a);
		}
		else
		{
			while ((*stack_a)->value != stack_min((*stack_a)))
				reverse_rotate_a(stack_a);
		}
	}
}
