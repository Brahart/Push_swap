/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:40:25 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/24 03:06:42 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	stack_size(t_stack *stack)
{
	int		len;
	t_stack	*tmp;

	len = 1;
	tmp = stack;
	while (tmp->next != stack)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

int	stack_max(t_stack *stack)
{
	int		i;
	t_stack	*tmp;

	tmp = stack;
	i = tmp->value;
	while (tmp->next != stack)
	{
		if (i < tmp->value)
			i = tmp->value;
		tmp = tmp->next;
	}
	if (i < tmp->value)
		i = tmp->value;
	return (i);
}

int	stack_min(t_stack *stack)
{
	int		i;
	t_stack	*tmp;

	tmp = stack;
	i = tmp->value;
	while (tmp->next != stack)
	{
		if (i > tmp->value)
			i = tmp->value;
		tmp = tmp->next;
	}
	if (i > tmp->value)
		i = tmp->value;
	return (i);
}

int	stack_last(t_stack *stack)
{
	int		i;
	t_stack	*tmp;

	tmp = stack;

	while(tmp->next != stack)
		tmp = tmp->next;
	i = tmp->value;
	return (i);
}

