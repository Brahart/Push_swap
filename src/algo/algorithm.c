/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:26:53 by asinsard          #+#    #+#             */
/*   Updated: 2025/02/14 22:00:31 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_three(t_stack **stack)
{
	if (stack_max((*stack)) == (*stack)->content)
	{
		rotate_a(stack, true);
		if (stack_min((*stack)) == (*stack)->next->content)
			swap_a(stack, true);
	}
	else if (stack_min(*stack) == (*stack)->content)
	{
		swap_a(stack, true);
		rotate_a(stack, true);
	}
	else if (stack_min(*stack) == (*stack)->next->content)
		swap_a(stack, true);
	else
		reverse_rotate_a(stack, true);
}

void	sort_a(t_stack **a, t_stack **b)
{
	int	len_b;

	len_b = stack_size(*b);
	while (len_b > 0)
	{
		if (((*b)->content > stack_max(*a)) || ((*b)->content < stack_min(*a)))
			find_min_and_move(a);
		else
			find_random_and_move(a, b);
		push_to_a(a, b, true);
		len_b--;
	}
	find_good_place(a);
}

void	sort_b(t_stack **a, t_stack **b)
{
	int	len_a;
	int	best;

	len_a = stack_size(*a);
	if ((len_a > 3) && (!check_is_sorted((*a))))
	{
		push_to_b(a, b, true);
		len_a--;
	}
	if ((len_a > 3) && (!check_is_sorted((*a))))
	{
		push_to_b(a, b, true);
		len_a--;
	}
	while ((len_a > 3) && (!check_is_sorted((*a))))
	{
		alloc_step(a, b);
		best = find_best_step(a);
		find_move_together(a, b, best);
		len_a--;
	}
	if (!check_is_sorted((*a)))
		sort_three(a);
}

void	algo_sort(t_stack **a)
{
	int		len;
	t_stack	*b;

	b = NULL;
	len = stack_size(*a);
	if (len == 2 && !check_is_sorted(*a))
		swap_a(a, true);
	else if (len == 3 && !check_is_sorted(*a))
		sort_three(a);
	else
		sort_b(a, &b);
	if (b != NULL)
		sort_a(a, &b);
}
