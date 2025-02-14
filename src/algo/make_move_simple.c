/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_move_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 02:55:28 by asinsard          #+#    #+#             */
/*   Updated: 2025/02/13 23:13:00 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	make_reverse_rotate(t_stack **stack, int rev_rot, int move)
{
	while (rev_rot < stack_size(*stack))
	{
		if (move == 1)
		{
			reverse_rotate_a(stack, true);
			rev_rot++;
		}
		else if (move == 2)
		{
			reverse_rotate_b(stack, true);
			rev_rot++;
		}
	}
}

void	make_rotate(t_stack **stack, int rot, int move)
{
	while (rot != 0)
	{
		if (move == 1)
		{
			rotate_a(stack, true);
			rot--;
		}
		else if (move == 2)
		{
			rotate_b(stack, true);
			rot--;
		}
	}
}

void	make_move_simple(t_stack **a, t_stack **b, int best)
{
	int	cost_a;
	int	cost_b;

	cost_a = find_nbr_rotate(*a, best, false);
	cost_b = pos_value_in_b(*b, best, false);
	if (cost_a > (stack_size(*a) / 2))
		make_reverse_rotate(a, cost_a, 1);
	else if (cost_a <= (stack_size(*a) / 2))
		make_rotate(a, cost_a, 1);
	if (cost_b > (stack_size(*b) / 2))
		make_reverse_rotate(b, cost_b, 2);
	else if (cost_b <= (stack_size(*b) / 2))
		make_rotate(b, cost_b, 2);
}
