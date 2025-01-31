/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_find_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:50:10 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/31 02:15:10 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	find_nbr_rotate(t_stack *stack, int value)
{
	int	i;

	i = 0;
	if (!stack)
		return (-1);
	while (stack->content != value)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

// int	find_place_in_a(t_stack *a, int push_value)
// {
// 	int 	i;
// 	int		max;
// 	int		min;
// 	t_stack	*tmp;

// 	i = 1;
// 	max = stack_max(a);
// 	min = stack_min(a);
// 	if (push_value < a->content && push_value > a->prev->content)
// 		i = 0;
// 	else if (push_value > max || push_value < min)
// 		i = find_nbr_rotate(a, min);
// 	else
// 	{
// 		tmp = a->next;
// 		while (a->content > push_value || tmp->content < push_value)
// 		{
// 			a = a->next;
// 			tmp = a->next;
// 			i++;
// 		}
// 	}
// 	return (i);
// }

// int	find_place_in_b(t_stack *b, int push_value)
// {
// 	int 	i;
// 	int		max;
// 	int		min;
// 	t_stack	*tmp;

// 	i = 1;
// 	max = stack_max(b);
// 	min = stack_min(b);
// 	if (push_value < b->content && push_value > b->prev->content)
// 		i = 0;
// 	else if (push_value > max || push_value < min)
// 		i = find_nbr_rotate(b, min);
// 	else
// 	{
// 		tmp = b->next;
// 		while (b->content > push_value || tmp->content < push_value)
// 		{
// 			b = b->next;
// 			tmp = b->next;
// 			i++;
// 		}
// 	}
// 	return (i);
// }

// void	take_index(t_stack *stack)
// {
// 	int		count;
// 	int		max;
// 	int		value;
// 	t_stack	*tmp;
// 	void	*start;

// 	count = stack_size(stack);
// 	max = stack_max(stack);
// 	value = 0;
// 	tmp = stack;
// 	start = stack;
// 	while (count != 0)
// 	{
// 		while (tmp->next != start)
// 		{
// 			if (tmp->content > stack->content)
// 				value++;
// 			tmp = tmp->next;
// 		}
// 		stack->index = value;
// 		value = 0;
// 		stack = stack->next;
// 		count--;
// 	}
// }
