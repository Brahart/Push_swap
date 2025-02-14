/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_position_in_stack.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 02:53:27 by asinsard          #+#    #+#             */
/*   Updated: 2025/02/13 23:10:10 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	value_is_min_or_max(t_stack *b, int value, bool flag)
{
	int	i;
	int	max;
	int	min;

	i = 1;
	max = stack_max(b);
	min = stack_min(b);
	if (b->content == min && value < min)
		return (0);
	while (b->content != min)
	{
		i++;
		b = b->next;
	}
	if (stack_size(b) > 2 && i > (stack_size(b) / 2) && flag == true)
	{
		i = stack_size(b) - i;
		i *= -1;
	}
	return (i);
}

int	value_is_random(t_stack *b, int value, bool flag)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = b;
	if (tmp->prev->content > value && tmp->content < value)
		return (0);
	while (1)
	{
		if (tmp->content > value && tmp->next->content < value)
		{
			i++;
			break ;
		}
		i++;
		tmp = tmp->next;
	}
	if (stack_size(b) > 2 && i > (stack_size(b) / 2) && flag == true)
	{
		i = stack_size(b) - i;
		i *= -1;
	}
	return (i);
}

int	pos_value_in_b(t_stack *b, int value, bool flag)
{
	int	i;

	if ((value > stack_max(b)) || (value < stack_min(b)))
		i = value_is_min_or_max(b, value, flag);
	else
		i = value_is_random(b, value, flag);
	if (i == stack_size(b))
		i = 0;
	return (i);
}

int	find_nbr_rotate(t_stack *stack, int value, bool flag)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = stack;
	if (tmp->content == value)
		return (0);
	while (tmp->content != value)
	{
		i++;
		tmp = tmp->next;
	}
	if (i > (stack_size(stack) / 2) && flag == true)
	{
		i = 0;
		while (tmp->next != stack)
		{
			tmp = tmp->next;
			i++;
		}
		i++;
		if (flag == true)
			i *= -1;
	}
	return (i);
}
