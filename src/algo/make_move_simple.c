#include "../../include/push_swap.h"


void	make_reverse_rotate(t_stack **stack, int rev_rot, int move)
{
	while (rev_rot != stack_size(*stack))
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

void	make_move_simple(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	int	rot;
	int	rev_rot;

	rot = 0;
	rev_rot = 0;
	if (cost_a > (stack_size(*a) / 2))
		make_reverse_rotate(a, cost_a, 1);
	else if (cost_a <= (stack_size(*a) / 2))
		make_rotate(a, cost_a, 1);
	if (cost_b > (stack_size(*b) / 2))
		make_reverse_rotate(b, cost_b, 2);
	else if (cost_b <= (stack_size(*b) / 2))
		make_rotate(b, cost_b, 2);
}
