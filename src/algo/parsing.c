/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:46:00 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/22 19:51:09 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	check_double(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*runner;

	if (!(*stack) || (*stack)->next == (*stack))
		return (0);
	tmp = (*stack);
	while (tmp->next != (*stack))
	{
		runner = tmp->next;
		while (runner != (*stack))
		{
			if (tmp->value == runner->value)
				return (1);
			runner = runner->next;
		}
		tmp = tmp->next;
	}
	return (0);
}