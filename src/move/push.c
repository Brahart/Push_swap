/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:55:19 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/29 19:55:28 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	push_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head;

	if (!stack_b || !(*stack_b))
		return ;
	head = (*stack_b);
	// if ((*stack_b)->next == (*stack_b))
	// 	(*stack_b) = NULL;
	(*stack_b) = (*stack_b)->next;
	(*stack_b)->prev = head->prev;
	head->prev->next = (*stack_b);
	if (!(*stack_a))
	{
		(*stack_a) = head;
		head->next = head;
		head->prev = head;
	}
	head->next = (*stack_a);
	head->prev = (*stack_a)->prev;
	(*stack_a)->prev->next = head;
	(*stack_a)->prev = head;
	(*stack_a) = head;
	ft_printf("pa\n");
}

void	push_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head;

	if (!stack_a || !(*stack_a))
		return ;
	head = (*stack_a);
	if ((*stack_a)->next == (*stack_a))
		(*stack_a) = NULL;
	(*stack_a) = (*stack_a)->next;
	(*stack_a)->prev = head->prev;
	head->prev->next = (*stack_a);
	if (!(*stack_b))
	{
		(*stack_b) = head;
		head->next = head;
		head->prev = head;
	}
	head->next = (*stack_b);
	head->prev = (*stack_b)->prev;
	(*stack_b)->prev->next = head;
	(*stack_b)->prev = head;
	(*stack_b) = head;
	ft_printf("pb\n");
}
