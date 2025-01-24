#include "../../include/push_swap.h"

int	calc_rarb_b(t_stack *stack_a, t_stack *stack_b, int value)
{
	int	i;

	i = find_place_in_b(stack_b, value);
	if (i < find_index(stack_a, value))
		i = find_index(stack_a, value);
	return (i);
}

// int	calc_rrarb_a(t_stack *stack_a, t_stack *stack_b, int value)
// {
// 	int	i;

// 	i = 0;
// 	if (find_place_in_a(stack_a, value))
// 		i = stack_size(stack_a) - find_place_in_a(stack_a, value);
// 	i += find_index(stack_b, value);
// 	return (i);
// }

int	calc_rrarb_b(t_stack *stack_a, t_stack *stack_b, int value)
{
	int	i;

	i = 0;
	if (find_index(stack_a, value))
		i = stack_size(stack_a) - find_index(stack_a, value);
	i += find_place_in_b(stack_b, value);
	return (i);
}

int calc_rarrb_b(t_stack *stack_a, t_stack *stack_b, int value)
{
	int	i;

	i = 0;
	if (find_place_in_b(stack_b, value))
		i = stack_size(stack_b) - find_place_in_b(stack_b, value);
	i += find_index(stack_a, value);
	return (i);
}

int	calc_rrarrb_b(t_stack *stack_a, t_stack *stack_b, int value)
{
	int	i;

	i = 0;
	if (find_place_in_b(stack_b, value))
		i = stack_size(stack_b) - find_place_in_a(stack_b, value);
	if (i < stack_size(stack_a) - find_index(stack_a, value) && find_index(stack_a, value))
		i = stack_size(stack_a) - find_index(stack_a, value);
	return (i);
}