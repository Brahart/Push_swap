#include "../../include/push_swap.h"

void	swap_a(t_pile **a)
{
	int	tmp;
	if ((*a)->value && (*a)->next->value)
	{
		tmp = (*a)->value;
		(*a)->value = (*a)->next->value;
		(*a)->next->value = tmp;
	}
	else
		return ;
}

void	swap_a(t_pile **b)
{
	int	tmp;

	if ((*b)->value && (*b)->next->value)
	{
		tmp = (*b)->value;
		(*b)->value = (*b)->next->value;
		(*b)->next->value = tmp;
	}
	else
		return ;
}