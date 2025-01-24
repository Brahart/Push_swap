#include "../../include/push_swap.h"

int	find_index(t_stack *stack, int value)
{
	int	i;

	i = 0;
	while (stack->value != value)
	{
		i++;
		stack = stack->next;
	}
	stack->index = 0;
	return (i);
}

int	find_place_in_a(t_stack *stack_a, int push_value)
{
	int 	i;
	int		max;
	int		min;
	t_stack	*tmp;

	i = 1;
	max = stack_max(stack_a);
	min = stack_min(stack_a);
	if (push_value < stack_a->value && push_value > stack_a->prev->value)
		i = 0;
	else if (push_value > max || push_value < min)
		i = find_index(stack_a, min);
	else
	{
		tmp = stack_a->next;
		while (stack_a->value > push_value || tmp->value < push_value)
		{
			stack_a = stack_a->next;
			tmp = stack_a->next;
			i++;
		}
	}
	return (i);
}

int	find_place_in_b(t_stack *stack_b, int push_value)
{
	int 	i;
	int		max;
	int		min;
	t_stack	*tmp;

	i = 1;
	max = stack_max(stack_b);
	min = stack_min(stack_b);
	if (push_value < stack_b->value && push_value > stack_b->prev->value)
		i = 0;
	else if (push_value > max || push_value < min)
		i = find_index(stack_b, min);
	else
	{
		tmp = stack_b->next;
		while (stack_b->value > push_value || tmp->value < push_value)
		{
			stack_b = stack_b->next;
			tmp = stack_b->next;
			i++;
		}
	}
	return (i);
}
