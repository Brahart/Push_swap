#include "../../include/push_swap.h"


int	value_is_min_or_max(t_stack *b, int value, bool flag)
{
	int	i;
	int	max;
	
	i = 0;
	max = stack_max(b);
	if (b->content == max)
		return (0);
	while (b->content != max)
	{
		b = b->next;
		i++;
	}
	if (stack_size(b) > 2 && i > (stack_size(b) / 2) && flag == true)
	{
		i = stack_size(b) - i;
		i *= -1;
	}
	return (i);
}

int	value_is_random(t_stack *b, int value, bool flag)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = b;
	if (tmp->prev->content > value && tmp->content < value)
		return (0);
	while (1)
	{
		if (tmp->content > value && tmp->next->content < value)
		{
			i++;
			break ;
		}
		i++;
		tmp = tmp->next;
	}
	if (stack_size(b) > 2 && i > (stack_size(b) / 2) && flag == true)
	{
		i = stack_size(b) - i;
		i *= -1;	
	}
	return (i);
}

int	find_place_in_b(t_stack *b, int value)
{
	int		i;

	i = 0;
	if ((value > stack_max(b)) || (value < stack_min(b)))
		i = 1;
	else
		i = 2;
	return (i);
}

int	pos_value_in_b(t_stack *b, int value, bool flag)
{
	int	i;

	i = find_place_in_b(b, value);
	if (i == 1)
		i = value_is_min_or_max(b, value, flag);
	else if (i == 2)
		i = value_is_random(b, value, flag);
	if (i == stack_size(b))
		i = 0;
	return (i);
}