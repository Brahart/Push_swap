/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_find_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:50:10 by asinsard          #+#    #+#             */
/*   Updated: 2025/02/06 20:09:07 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	find_nbr_rotate(t_stack *stack, int value)
{
	int	i;
	int	len;
	t_stack	*tmp;

	i = 0;
	len = stack_size(stack);
	tmp = stack;
	if (tmp->content == value)
		return (0);
	while (tmp->content != value)
	{
		i++;
		tmp = tmp->next;
	}
	if (i > (len / 2))
	{
		i = 0;
		while (tmp->next != stack)
		{
			tmp = tmp->next;
			i++;
		}
		i++;
	}
	return (i);
}
