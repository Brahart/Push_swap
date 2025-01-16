#include "../../include/push_swap.h"

void	swap_a(t_pile **pile_a)
{
	int	tmp;
	if ((*pile_a)->value && (*pile_a)->next->value)
	{
		tmp = (*pile_a)->value;
		(*pile_a)->value = (*pile_a)->next->value;
		(*pile_a)->next->value = tmp;
	}
	write(1, "sa\n", 3);
}

void	swap_a(t_pile **pile_b)
{
	int	tmp;

	if ((*pile_b)->value && (*pile_b)->next->value)
	{
		tmp = (*pile_b)->value;
		(*pile_b)->value = (*pile_b)->next->value;
		(*pile_b)->next->value = tmp;
	}
	write(1, "sb\n", 3);
}

void	swap_ss(t_pile **a, t_pile **b)
{
	swap_a(a);
	swap_b(b);
}