/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:26:53 by asinsard          #+#    #+#             */
/*   Updated: 2025/02/03 20:00:26 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_three(t_stack **stack)
{
	if (stack_max((*stack)) == (*stack)->content)
	{
		rotate_a(stack, true);
		if (stack_min((*stack)) == (*stack)->next->content)
			swap_a(stack);
	}
	else if (stack_min(*stack) == (*stack)->content)
	{
		swap_a(stack);
		rotate_a(stack, true);
	}
	else if (stack_min(*stack) == (*stack)->next->content)
		swap_a(stack);
	else
		reverse_rotate_a(stack, true);
}

// void	find_min_and_push(t_stack **stack_a, t_stack **stack_b)
// {
// 	int		i;
// 	int		index;
// 	int		len;

// 	index = find_nbr_rotate((*stack_a), stack_min((*stack_a)));
// 	len = stack_size((*stack_a));
// 	if (index > len / 2)
// 	{
// 		i = index;
// 		while (i != len)
// 		{
// 			reverse_rotate_a(stack_a);
// 			i++;
// 		}
// 	}
// 	else if (index <= len / 2)
// 	{
// 		i = index;
// 		while (i != 0)
// 		{
// 			rotate_a(stack_a);
// 			i--;
// 		}
// 	}
// 	push_to_b(stack_a, stack_b);
// }

void	make_reverse_rotate_together(t_stack **a, t_stack **b, int rev_rot)
{
	if (rev_rot > 0)
	{
		while (rev_rot != 0)
		{
			reverse_rotate_a(a, true);
			rev_rot--;
		}
	}
	else if (rev_rot < 0)
	{
		while (rev_rot != 0)
		{
			reverse_rotate_b(b, true);
			rev_rot++;
		}
	}
	push_to_b(a, b);
}

void	make_rotate_together(t_stack **a, t_stack **b, int rot)
{
	if (rot > 0)
	{
		while (rot != 0)
		{
			rotate_a(a, true);
			rot--;
		}
	}
	else if (rot < 0)
	{
		while (rot != 0)
		{
			rotate_b(b, true);
			rot++;
		}
	}
	push_to_b(a, b);
}

void	make_reverse_rotate(t_stack **stack, int rev_rot, int i)
{
	while (rev_rot != 0)
	{
		if (i == 1)
		{
			reverse_rotate_a(stack, true);
			rev_rot--;
		}
		else if (i == 2)
		{
			reverse_rotate_b(stack, true);
			rev_rot--;
		}
	}
}

void	make_rotate(t_stack **stack, int rot, int i)
{
	while (rot != 0)
	{
		if (i == 1)
		{
			rotate_a(stack, true);
			rot--;
		}
		else if (i == 2)
		{
			rotate_b(stack, true);
			rot--;
		}
	}
}

void	make_move_together(t_stack **a, t_stack **b, int cost_a, int cost_b, int move)
{
	if (move == 1)
	{
		while ((cost_a >= 0) || (cost_b >= 0))
		{
			ft_printf("cost_a == %d || cost_b == %d\n");
			reverse_rotate_rr(a, b);
			cost_a--;
			cost_b--;
		}
		cost_a -= cost_b;
		make_reverse_rotate_together(a, b, cost_a);
	}
	else if (move == 2)
	{
		while ((cost_a != 0) || (cost_b != 0))
		{
			rotate_rr(a, b);
			cost_a--;
			cost_b--;
		}
		cost_a -= cost_b;
		make_rotate_together(a, b, cost_a);
	}
}

int	r_or_rr(int cost_a, int cost_b, t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;
	int	sort_of;

	len_a = stack_size(a);
	len_b = stack_size(b);
	sort_of = 0;
	if (cost_a > len_a / 2)
		sort_of += 1;
	else
		sort_of += 2;
	if (cost_b > len_b / 2)
		sort_of += 1;
	else
		sort_of += 2;
	return (sort_of);
}

void	make_move_simple(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	int	rot;
	int	rev_rot;

	rot = 0;
	rev_rot = 0;
	if (cost_a > stack_size(*a) / 2)
		make_reverse_rotate(a, cost_a, 1);
	else if (cost_a < stack_size(*a) / 2)
		make_rotate(a, cost_a, 1);
	if (cost_b > stack_size(*b) / 2)
		make_reverse_rotate(b, cost_b, 2);
	else if (cost_b < stack_size(*b) / 2)
		make_rotate(b, cost_b, 2);
}


int	value_is_max(t_stack *b, int value)
{
	int	i;
	int	max;
	
	i = 0;
	max = stack_max(b);
	while (b->content != max)
	{
		i++;
		b = b->next;
	}
	return (i);
}

int	value_is_min(t_stack *b, int value)
{
	int	i;
	int	min;
	
	i = 0;
	min = stack_min(b);
	while (b->content != min)
	{
		i++;
		b = b->next;
	}
	return (i);
}

int	value_is_random(t_stack *b, int value)
{
	int	i;

	i = 0;
	while (b->next != b)
	{
		i++;
		if (b->content > value && b->next->content < value)
			return (i);
		b = b->next;
	}
	return (0);
}

int	find_place_in_b(t_stack *b, int value) // fonction pour avoir la position de a->content dans b
{
	int	i;

	i = 0;
	if (value > stack_max(b))
		i = 1;
	else if (value < stack_min(b))
		i = 2;
	else
		i = 3;
	return (i);
}

int	pos_value_in_b(t_stack *b, int value) // suite de la fonction find_place_in_b
{
	int	i;

	i = find_place_in_b(b, value);
	if (i == 1)
		i = value_is_max(b, value);
	else if (i == 2)
		i = value_is_min(b, value);
	else if (i == 3)
		i = value_is_random(b, value);
	return (i);
}

int	find_best_step(t_stack **a) // fonction pour trouver le chiffre le moins cher de a
{
	int	best;
	t_stack	*tmp;

	best = 0;
	tmp = (*a);
	while ((tmp->next != (*a)))
	{
		if (tmp->step > tmp->next->step)
			best = tmp->next->content;
		tmp = tmp->next;
	}
	return (best);
}

void	alloc_step(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		cost_a;
	int		cost_b;

	tmp = (*a);
	while (tmp->next != *a)
	{
		cost_a = find_nbr_rotate(*a, tmp->content); // nombre de rotate ou rr qu'il faut pour ramener a a la pos 0;
		cost_b = pos_value_in_b(*b, tmp->content); // nombre de rotate ou rr pour set la bonne position de a->content dans b;
		tmp->step = cost_a + cost_b;
		tmp = tmp->next;
	}
}

void	find_move_together(t_stack **a, t_stack **b, int best)
{
	int	cost_a;
	int	cost_b;
	int	rot;
	int	sort_of;
	int	move;

	cost_a = find_nbr_rotate(*a, best); //nombre d'instruction pour a
	cost_b = pos_value_in_b(*b, best); // nombre d'instruction pour b
	rot = 0;
	sort_of = r_or_rr(cost_a, cost_b, *a, *b);
	if ((sort_of / 4 == 0) || (sort_of / 2) == 0)
	{
		if (sort_of / 4 == 0)
		{
			move = 1;
			make_move_together(a, b, cost_a, cost_b, move);	
		}
		else
		{
			move = 2;
			make_move_together(a, b, cost_a, cost_b, move);
		}
	}
	else
		make_move_simple(a, b, cost_a, cost_b);
}

t_stack	*sort_b(t_stack **a)
{
	t_stack	*b;
	int		len;
	int		best;

	b = NULL;
	len = stack_size((*a));
	if ((len > 3) && (!check_is_sorted((*a))))
		push_to_b(a, &b);
	if ((len > 3) && (!check_is_sorted((*a))))
		push_to_b(a, &b);
	while ((len > 3) && (!check_is_sorted((*a))))
	{
		// find_min_and_push(a, &b);
		alloc_step(a, &b);
		best = find_best_step(a);
		find_move_together(a, &b, best);
		display_list(b, "stack_a");
		len--;
	}
	if (!check_is_sorted((*a)))
		sort_three(a);
	len = stack_size(b);
	while (len > 0)
	{
		push_to_a(a, &b);
		len--;
	}
	return (b);
}

void	algo_sort(t_stack **stack_a)
{
	int		len;
	int		i;
	t_stack	*stack_b;

	len = stack_size(*stack_a);
	stack_b = NULL;
	if (len == 2 && !check_is_sorted((*stack_a)))
		swap_a(stack_a);
	else
	{
		stack_b = sort_b(stack_a);
		
	}
}
