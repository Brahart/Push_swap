/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:26:53 by asinsard          #+#    #+#             */
/*   Updated: 2025/02/07 01:49:41 by asinsard         ###   ########lyon.fr   */
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
		while (rev_rot > 0)
		{
			reverse_rotate_a(a, true);
			rev_rot--;
		}
	}
	else if (rev_rot < 0)
	{
		while (rev_rot < 0)
		{
			reverse_rotate_b(b, true);
			rev_rot++;
		}
	}
}

void	make_rotate_together(t_stack **a, t_stack **b, int rot)
{
	if (rot > 0)
	{
		while (rot > 0)
		{
			rotate_a(a, true);
			rot--;
		}
	}
	else if (rot < 0)
	{
		while (rot < 0)
		{
			rotate_b(b, true);
			rot++;
		}
	}
}

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

void	make_move_together(t_stack **a, t_stack **b, int cost_a, int cost_b, int move)
{
	if (move == 1)
	{
		while ((cost_a >= 0) || (cost_b >= 0))
		{
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
	if (cost_a != 0 && cost_a > len_a / 2)
		sort_of += 1;
	if (cost_a != 0 && cost_a <= len_a / 2)
		sort_of += 3;
	if (cost_b != 0 && cost_b > len_b / 2)
		sort_of += 5;
	if (cost_b != 0 && cost_b <= len_b / 2)
		sort_of += 7;
	return (sort_of);
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


int	value_is_max(t_stack *b, int value, bool flag)
{
	int	i;
	int	min;
	
	i = 0;
	min = stack_min(b);
	if ((b->content == min))
		return (0);
	while (b->content != min)
	{
		b = b->next;
		i++;
	}
	if (stack_size(b) > 2 && i > (stack_size(b) / 2) && flag == true)
		i = stack_size(b) - i;	
	return (i);
}

int	value_is_min(t_stack *b, int value, bool flag)
{
	int	i;
	int	max;
	
	i = 0;
	max = stack_max(b);
	if ((b->content == max))
		return (0);
	while (b->content != max)
	{
		i++;
		b = b->next;
	}
	if (stack_size(b) > 2 && i > (stack_size(b) / 2) && flag == true)
		i = stack_size(b) - i;
	return (i);
}

int	value_is_random(t_stack *b, int value, bool flag)
{
	int		i;

	i = 0;
	while (1)
	{
		if (b->content > value && b->next->content < value)
			break ;
		i++;
		b = b->next;
	}
	if (stack_size(b) > 2 && i > (stack_size(b) / 2) && flag == true)
		i = stack_size(b) - i;
	ft_printf("i == %d\n", i);
	return (i);
}

int	find_place_in_b(t_stack *b, int value) // fonction pour avoir la position de a->content dans stack
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

int	pos_value_in_b(t_stack *b, int value, bool flag) // suite de la fonction find_place_in_b
{
	int	i;

	i = find_place_in_b(b, value);
	if (i == 1)
		i = value_is_max(b, value, flag);
	else if (i == 2)
		i = value_is_min(b, value, flag);
	else if (i == 3)
		i = value_is_random(b, value, flag);
	return (i);
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
			best = tmp->step;
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
		cost_a = find_nbr_rotate(*a, tmp->content); // nombre de rotate ou rr qu'il faut pour ramener a a la pos 0;
		cost_b = pos_value_in_b(*b, tmp->content, true); // nombre de rotate ou rr pour set la bonne position de a->content dans b;
		ft_printf("[%d] || cost_a == %d || cost_b == %d\n", tmp->content, cost_a, cost_b);
		tmp->step = cost_a + cost_b;
		tmp = tmp->next;
	}
	cost_a = find_nbr_rotate(*a, tmp->content);
	cost_b = pos_value_in_b(*b, tmp->content, true);
	tmp->step = cost_a + cost_b;
}

void	find_move_together(t_stack **a, t_stack **b, int best)
{
	int	cost_a;
	int	cost_b;
	int	rot;
	int	sort_of;
	int	move;

	cost_a = find_nbr_rotate(*a, best); //nombre d'instruction pour a
	cost_b = pos_value_in_b(*b, best, false); // nombre d'instruction pour b
	rot = 0;
	sort_of = r_or_rr(cost_a, cost_b, *a, *b);
	if (sort_of == 6)
	{
		move = 1;
		make_move_together(a, b, cost_a, cost_b, move);	
	}
	else if (sort_of == 10)
	{
		move = 2;
		make_move_together(a, b, cost_a, cost_b, move);
	}
	else
		make_move_simple(a, b, cost_a, cost_b);
	push_to_b(a, b);
}

void	find_max_and_move(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		max;
	int		move;

	max = stack_max(*a);
	move = 0;
	tmp = *a;
	while (tmp->content != max)
	{
		move++;
		tmp = tmp->next;
	}
	if (move > (stack_size(*a) / 2))
		make_reverse_rotate(a, move, 1);
	if (move <= (stack_size(*a) / 2))
		make_rotate(a, move, 1);
}

void	find_min_and_move(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		min;
	int		move;

	min = stack_min(*a);
	move = 0;
	tmp = *a;
	while (tmp->content != min)
	{
		move++;
		tmp = tmp->next;
	}
	if (move > (stack_size(*a) / 2))
		make_reverse_rotate(a, move, 1);
	if (move <= (stack_size(*a) / 2))
		make_rotate(a, move, 1);
}

void	find_random_and_move(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		random;
	int		move;

	random = (*b)->content;
	move = 0;
	tmp = *a;
	while (random > tmp->content && random < tmp->next->content)
	{
		move++;
		tmp = tmp->next;
	}
	if (move > (stack_size(*a) / 2))
		make_reverse_rotate(a, move, 1);
	if (move <= (stack_size(*a) / 2))
		make_rotate(a, move, 1);
}

void	find_good_place(t_stack **a)
{
	int		min;
	int		i;
	t_stack	*tmp;

	min = stack_min(*a);
	i = 0;
	tmp = *a;
	while (tmp->content != min)
	{
		i++;
		tmp = tmp->next;
	}
	if (min <= (stack_size(*a) / 2))
	{
		while ((*a)->content != stack_min((*a)))
			reverse_rotate_a(a, true);
	}
	else
	{
		while ((*a)->content != stack_min(*a))
			rotate_a(a, true);
	}
}

void	sort_a(t_stack **a, t_stack **b)
{
	int	len_b;
	int	min;

	len_b = stack_size(*b);
	while (len_b > 0)
	{
		if ((*b)->content > stack_max(*a))
			find_max_and_move(a, b);
		else if ((*b)->content < stack_min(*a))
			find_min_and_move(a, b);
		else
			find_random_and_move(a, b);
		push_to_a(a, b);
		len_b--;		
	}
	find_good_place(a);
}

void	sort_b(t_stack **a)
{
	t_stack	*b;
	int		len;
	int		best;

	b = NULL;
	if ((stack_size(*a) > 3) && (!check_is_sorted((*a))))
		push_to_b(a, &b);
	if ((stack_size(*a) > 3) && (!check_is_sorted((*a))))
		push_to_b(a, &b);
	len = stack_size(*a);
	while ((len > 3) && (!check_is_sorted((*a))))
	{
		display_list(*a, "a");
		display_list(b, "b");
		alloc_step(a, &b);
		best = find_best_step(a);
		find_move_together(a, &b, best);
		len--;
	}
	if (!check_is_sorted((*a)))
		sort_three(a);
	if (b != NULL)
		sort_a(a, &b);
}


void	algo_sort(t_stack **stack_a)
{
	int		len;
	int		i;

	len = stack_size(*stack_a);
	if (len == 2 && !check_is_sorted((*stack_a)))
		swap_a(stack_a);
	else
	{
		sort_b(stack_a);
		
	}
}
