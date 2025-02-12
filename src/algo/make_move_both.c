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

void	make_move_together(t_stack **a, t_stack **b, int cost_a, int cost_b, int move)
{
	if (move == 1)
	{
		while ((cost_a > 0) && (cost_b > 0))
		{
			reverse_rotate_rr(a, b);
			cost_a--;
			cost_b--;
		}
		cost_a -= cost_b;
		make_reverse_rotate_together(a, b, cost_a);
	}
	else if (move == 2)
	{
		while ((cost_a != 0) && (cost_b != 0))
		{
			rotate_rr(a, b);
			cost_a--;
			cost_b--;
		}
		cost_a -= cost_b;
		make_rotate_together(a, b, cost_a);
	}
}

void	find_move_together(t_stack **a, t_stack **b, int best)
{
	int	cost_a;
	int	cost_b;
	int	rot;
	int	sort_of;
	int	move;

	cost_a = find_nbr_rotate(*a, best, false);
	cost_b = pos_value_in_b(*b, best, false);
	// ft_printf("index == %d || cost_a == %d || cost_b == %d\n", best, cost_a, cost_b);
	rot = 0;
	sort_of = r_or_rr(&cost_a, &cost_b, *a, *b);
	if (sort_of == 6)
	{
		move = 1;
		make_move_together(a, b, cost_a, cost_b, move);	
	}
	else if (sort_of == 10)
	{
		move = 2;
		make_move_together(a, b, cost_a, cost_b, move);
	}
	else
		make_move_simple(a, b, cost_a, cost_b);
	push_to_b(a, b);
}
