#include "../../include/push_swap.h"

void	comp_rot(t_stack **tmp, int cost_a, int cost_b)
{
		if (cost_a == cost_b)
			(*tmp)->step = cost_a;
		if (cost_a > cost_b)
			(*tmp)->step = cost_a;
		else
			(*tmp)->step = cost_b;
	
}

void	comp_rev_rot(t_stack **tmp, int cost_a, int cost_b)
{
		if (cost_a == cost_b)
			(*tmp)->step = cost_b *(-1);
		if (cost_a > cost_b)
			(*tmp)->step = cost_b * (-1);
		else
			(*tmp)->step = cost_a * (-1);
	
}

void	comp_move(t_stack **tmp, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		comp_rev_rot(tmp, cost_a, cost_b);
	else if (cost_a > 0 && cost_b > 0)
		comp_rot(tmp, cost_a, cost_b);
	else
	{
		if (cost_a < 0)
			cost_a *= -1;
		else if (cost_b < 0)
			cost_b *= -1;
		(*tmp)->step = cost_b + cost_a;
	}
	// ft_printf("Comp_mouv: [%d] || cost_a == %d || cost_b == %d\n", (*tmp)->content, cost_a, cost_b);
}

int	find_best_step(t_stack **a)
{
	int	best;
	int	len;
	t_stack	*tmp;

	best = 0;
	tmp = *a;
	best = tmp->step;
	while ((tmp->next != *a))
	{
		if (best > tmp->next->step)
			best = tmp->next->step;
		tmp = tmp->next;
	}
	tmp = *a;
	while (1)
	{
		if (tmp->step == best)
		{
			best = tmp->content;
			break ;
		}
		tmp = tmp->next;
	}
	// ft_printf("tmp == [%d] || tmp->next == [%d] || best == %d\n", tmp->content, tmp->next->content, best);
	return (best);
}

void	alloc_step(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		cost_a;
	int		cost_b;

	tmp = (*a);
	cost_a = 0;
	cost_b = 0;
	while (tmp->next != *a)
	{
		cost_a = find_nbr_rotate(*a, tmp->content, true); // nombre de rotate ou rr qu'il faut pour ramener a a la pos 0;
		cost_b = pos_value_in_b(*b, tmp->content, true); // nombre de rotate ou rr pour set la bonne position de a->content dans b;
		comp_move(&tmp, cost_a, cost_b);
		// ft_printf("[%d] || step == %d || cost_a == %d || cost_b == %d\n", tmp->content, tmp->step, cost_a, cost_b);
		tmp = tmp->next;
	}
	cost_a = find_nbr_rotate(*a, tmp->content, true);
	cost_b = pos_value_in_b(*b, tmp->content, true);
	comp_move(&tmp, cost_a, cost_b);
	// ft_printf("[%d] || step == %d || cost_a == %d || cost_b == %d\n\n\n", tmp->content, tmp->step, cost_a, cost_b);
}

