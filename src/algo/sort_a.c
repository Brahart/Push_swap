/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 02:56:15 by asinsard          #+#    #+#             */
/*   Updated: 2025/02/14 01:44:51 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	find_good_place(t_stack **stack)
{
	int		min;
	int		i;
	t_stack	*tmp;

	min = stack_min(*stack);
	i = 0;
	tmp = *stack;
	while (tmp->content != min)
	{
		i++;
		tmp = tmp->next;
	}
	if (i <= (stack_size(*stack) / 2))
	{
		while ((*stack)->content != stack_min((*stack)))
			rotate_a(stack, true);
	}
	else
	{
		while ((*stack)->content != stack_min(*stack))
			reverse_rotate_a(stack, true);
	}
}

void	find_move_simple(t_stack **a, t_stack *tmp, int move, int value)
{
	if (move <= (stack_size(*a) / 2))
		make_rotate(a, move, 1);
	if (move > (stack_size(*a) / 2))
		make_reverse_rotate(a, move, 1);
	if (value > tmp->prev->prev->content && value < tmp->prev->content)
		reverse_rotate_b(a, true);
}

void	find_random_and_move(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		value;
	int		move;

	value = (*b)->content;
	move = 0;
	tmp = *a;
	if ((tmp->content < stack_min(*a) || (tmp->content > stack_max(*a))))
	{
		move++;
		tmp = tmp->next;
	}
	while (1)
	{
		if (tmp->content < value && tmp->next->content > value)
		{
			move++;
			break ;
		}
		move++;
		tmp = tmp->next;
	}
	find_move_simple(a, tmp, move, value);
}

void	find_min_and_move(t_stack **a)
{
	t_stack	*tmp;
	int		min;
	int		move;

	min = stack_min(*a);
	move = 0;
	tmp = *a;
	while (tmp->content != min)
	{
		move++;
		tmp = tmp->next;
	}
	if (move > (stack_size(*a) / 2))
		make_reverse_rotate(a, move, 1);
	if (move <= (stack_size(*a) / 2))
		make_rotate(a, move, 1);
}
