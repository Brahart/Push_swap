/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:55:19 by asinsard          #+#    #+#             */
/*   Updated: 2025/02/14 04:21:04 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../libft/include/ft_printf.h"

void	push_to_a(t_stack **a, t_stack **b, bool flag)
{
	t_stack	*head;

	if (!b || !(*b))
		return ;
	head = (*b);
	(*b) = (*b)->next;
	(*b)->prev = head->prev;
	head->prev->next = (*b);
	if (!(*a))
	{
		(*a) = head;
		head->next = head;
		head->prev = head;
	}
	head->next = (*a);
	head->prev = (*a)->prev;
	(*a)->prev->next = head;
	(*a)->prev = head;
	(*a) = head;
	if (flag == true)
		ft_printf("pa\n");
}

void	push_to_b(t_stack **a, t_stack **b, bool flag)
{
	t_stack	*head;

	if (!a || !(*a))
		return ;
	head = (*a);
	(*a) = (*a)->next;
	(*a)->prev = head->prev;
	head->prev->next = (*a);
	if (!(*b))
	{
		(*b) = head;
		head->next = head;
		head->prev = head;
	}
	head->next = (*b);
	head->prev = (*b)->prev;
	(*b)->prev->next = head;
	(*b)->prev = head;
	(*b) = head;
	if (flag == true)
		ft_printf("pb\n");
}
