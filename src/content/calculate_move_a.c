#include "../../include/push_swap.h"

int	calc_rarb_a(t_stack *stack_a, t_stack *stack_b, int value)
{
	int	i;

	i = find_place_in_a(stack_a, value);
	if (i < find_index(stack_b, value))
		i = find_index(stack_b, value);
	return (i);
}

int	calc_rrarb_a(t_stack *stack_a, t_stack *stack_b, int value)
{
	int	i;

	i = 0;
	if (find_place_in_a(stack_a, value))
		i = stack_size(stack_a) - find_place_in_a(stack_a, value);
	i += find_index(stack_b, value);
	return (i);
}

int calc_rarrb_a(t_stack *stack_a, t_stack *stack_b, int value)
{
	int	i;

	i = 0;
	if (find_index(stack_b, value))
		i = stack_size(stack_b) - find_index(stack_b, value);
	i += find_place_in_a(stack_a, value);
	return (i);
}

int	calc_rrarrb_a(t_stack *stack_a, t_stack *stack_b, int value)
{
	int	i;

	i = 0;
	if (find_place_in_b(stack_a, value))
		i = stack_size(stack_a) - find_place_in_a(stack_a, value);
	if (i < stack_size(stack_b) - find_index(stack_b, value) && find_index(stack_b, value))
		i = stack_size(stack_b) - find_index(stack_b, value);
	return (i);
}