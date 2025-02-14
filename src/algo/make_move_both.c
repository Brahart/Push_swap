/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_move_both.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 02:53:56 by asinsard          #+#    #+#             */
/*   Updated: 2025/02/13 23:38:03 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	make_reverse_rotate_together(t_stack **a, t_stack **b, int rev_rot)
{
	if (rev_rot > 0)
	{
		while (rev_rot > 0)
		{
			reverse_rotate_a(a, true);
			rev_rot--;
		}
	}
	else if (rev_rot < 0)
	{
		while (rev_rot < 0)
		{
			reverse_rotate_b(b, true);
			rev_rot++;
		}
	}
}

void	make_rotate_together(t_stack **a, t_stack **b, int rot)
{
	if (rot > 0)
	{
		while (rot > 0)
		{
			rotate_a(a, true);
			rot--;
		}
	}
	else if (rot < 0)
	{
		while (rot < 0)
		{
			rotate_b(b, true);
			rot++;
		}
	}
}

void	make_rrr(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	while ((cost_a > 0) && (cost_b > 0))
	{
		reverse_rotate_rr(a, b, true);
		cost_a--;
		cost_b--;
	}
	cost_a -= cost_b;
	make_reverse_rotate_together(a, b, cost_a);
}

void	make_rr(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	while ((cost_a != 0) && (cost_b != 0))
	{
		rotate_rr(a, b, true);
		cost_a--;
		cost_b--;
	}
	cost_a -= cost_b;
	make_rotate_together(a, b, cost_a);
}

void	find_move_together(t_stack **a, t_stack **b, int best)
{
	int	cost_a;
	int	cost_b;
	int	sort_of;

	cost_a = find_nbr_rotate(*a, best, false);
	cost_b = pos_value_in_b(*b, best, false);
	sort_of = r_or_rr(&cost_a, &cost_b, *a, *b);
	if (sort_of == 6)
		make_rrr(a, b, cost_a, cost_b);
	else if (sort_of == 10)
		make_rr(a, b, cost_a, cost_b);
	else
		make_move_simple(a, b, best);
	push_to_b(a, b, true);
}
