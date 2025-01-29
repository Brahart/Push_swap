/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:26:53 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/29 22:50:57 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_three(t_stack **stack)
{
	if (stack_max((*stack)) == (*stack)->content)
	{
		rotate_a(stack);
		if (stack_min((*stack)) == (*stack)->next->content)
			swap_a(stack);
	}
	else if (stack_min(*stack) == (*stack)->content)
	{
		swap_a(stack);
		rotate_a(stack);
	}
	else if (stack_min(*stack) == (*stack)->next->content)
		swap_a(stack);
	else
		reverse_rotate_a(stack);
}

void	find_min_and_push(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	int		index;
	int		len;

	index = find_nbr_rotate((*stack_a), stack_min((*stack_a)));
	len = stack_size((*stack_a));
	if (index > len / 2)
	{
		i = index;
		while (i != len)
		{
			reverse_rotate_a(stack_a);
			i++;
		}
	}
	else if (index <= len / 2)
	{
		i = index;
		while (i != 0)
		{
			rotate_a(stack_a);
			i--;
		}
	}
	push_to_b(stack_a, stack_b);
}

int find_position(t_list *stack, int value)
{
	t_list *current;
	int	i;
	int len;
	int pos;

	current = stack;
	i = 0;
	len = stack_size(stack);
	pos = 0;
	if (value > get_max(stack) || value < get_min(stack))
		pos = find_nbr_rotate(stack, stack_min(stack));
	else 
	{
		while (i < len) 
		{
			if (current->content < value && current->next->content > value)
			{
				pos = i + 1;
				break ;
			}
			current = current->next;
			i++;
		}
	}
	return (pos);
}

int calculate_double_rotation_cost(t_list *a, t_list *b, int value) 
{
	int	cost_a;
	int	cost_b;

	cost_a = find_rotation_cost_in_a(a, value);
	cost_b = find_rotation_cost_in_b(b, value);
	if ((cost_a <= stack_size(a) / 2 && cost_b <= stack_size(b) / 2)
		|| (cost_a > stack_size(a) / 2 && cost_b > stack_size(b) / 2))
	{
		if (cost_a > cost_b)
			return (cost_a);
		else
			return (cost_b);
	}
	return (cost_a + cost_b);
}

t_stack	*sort_b(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		len;

	stack_b = NULL;
	len = stack_size((*stack_a));
	// if ((len > 3) && (!check_is_sorted((*stack_a))))
	// 	push_to_b(stack_a, &stack_b);
	// if ((len > 3) && (!check_is_sorted((*stack_a))))
	// 	push_to_b(stack_a, &stack_b);
	while ((len > 3) && (!check_is_sorted((*stack_a))))
		find_min_and_push(stack_a, &stack_b);
	if (!check_is_sorted((*stack_a)))
		sort_three(stack_a);
	len = stack_size(stack_b);
	while (len > 0)
	{
		push_to_a(stack_a, &stack_b);
		len--;
	}
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
		
	}
}
