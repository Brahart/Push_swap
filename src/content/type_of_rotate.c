#include "../../include/push_swap.h"

int	rotate_type_ba(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp;
	int		i;

	tmp = stack_b;
	i = calc_rarb_a(stack_a, stack_b, stack_b->value);
	while (tmp->next != stack_b)
	{
		if (i > calc_rarrb_a(stack_a, stack_b, tmp->value))
			i = calc_rarrb_a(stack_a, stack_b, tmp->value);
		if (i > calc_rrarb_a(stack_a, stack_b, tmp->value))
			i = calc_rrarb_a(stack_a, stack_b, tmp->value);
		if (i > calc_rarb_a(stack_a, stack_b, tmp->value))
			i = calc_rarb_a(stack_a, stack_b, tmp->value);
		if (i > calc_rrarrb_a(stack_a, stack_b, tmp->value))
			i = calc_rrarrb_a(stack_a, stack_b, tmp->value);
		tmp = tmp->next;
	}
	return (i);
}

int	rotate_type_ab(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp;
	int		i;

	tmp = stack_a;
	i = calc_rarb_b(stack_a, stack_b, stack_a->value);
	while (tmp->next != stack_a)
	{
		if (i > calc_rarrb_b(stack_a, stack_b, tmp->value))
			i = calc_rarrb_b(stack_a, stack_b, tmp->value);
		if (i > calc_rrarb_b(stack_a, stack_b, tmp->value))
			i = calc_rrarb_b(stack_a, stack_b, tmp->value);
		if (i > calc_rarb_b(stack_a, stack_b, tmp->value))
			i = calc_rarb_b(stack_a, stack_b, tmp->value);
		if (i > calc_rrarrb_b(stack_a, stack_b, tmp->value))
			i = calc_rrarrb_b(stack_a, stack_b, tmp->value);
		tmp = tmp->next;
	}
	return (i);
}