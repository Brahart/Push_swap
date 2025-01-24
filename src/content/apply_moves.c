#include "../../include/push_swap.h"

int	move_rarb(t_stack **stack_a, t_stack **stack_b, int value, char c)
{
	if (c == 'a')
	{
		while ((*stack_a)->value != value && find_place_in_b((*stack_b), value) > 0)
			reverse_rotate_rr(stack_a, stack_b);
		while ((*stack_a)->value != value)
			reverse_rotate_a(stack_a);
		while (find_place_in_b((*stack_b), value) > 0)
			reverse_rotate_b(stack_b);
		push_to_b(stack_a, stack_b);
	}
	else
	{
		while ((*stack_b)->value != value && find_place_in_b((*stack_a), value) > 0)
			reverse_rotate_rr(stack_a, stack_b);
		while ((*stack_b)->value != value)
			reverse_rotate_b(stack_b);
		while (find_place_in_b((*stack_b), value) > 0)
			reverse_rotate_a(stack_a);
		push_to_a(stack_a, stack_b);
	}
	return (-1);
}

int	move_rrarb(t_stack **stack_a, t_stack **stack_b, int value, char c)
{
	if (c == 'a')
	{
		while ((*stack_a)->value != value)
			reverse_rotate_a(stack_a);
		while (find_place_in_b((*stack_b), value) > 0)
			rotate_b(stack_b);
		push_to_b(stack_a, stack_b);
	}
	else
	{
		while (find_place_in_a((*stack_a), value) > 0)
			reverse_rotate_a(stack_a);
		while ((*stack_b)->value != value)
			rotate_b(stack_b);
		push_to_a(stack_a, stack_b);
	}
	return (-1);
}

int	move_rarrb(t_stack **stack_a, t_stack **stack_b, int value, char c)
{
	if (c == 'a')
	{
		while ((*stack_a)->value != value)
			rotate_a(stack_a);
		while (find_place_in_b((*stack_b), value) > 0)
			reverse_rotate_b(stack_b);
		push_to_b(stack_a, stack_b);
	}
	else
	{
		while (find_place_in_a((*stack_a), value) > 0)
			rotate_a(stack_a);
		while ((*stack_b)->value != value)
			reverse_rotate_b(stack_b);
		push_to_a(stack_a, stack_b);
	}
	return (-1);
}

int	move_rrarrb(t_stack **stack_a, t_stack **stack_b, int value, char c)
{
	if (c == 'a')
	{
		while ((*stack_a)->value != value && find_place_in_b((*stack_b), value) > 0)
			reverse_rotate_rr(stack_a, stack_b);
		while ((*stack_a)->value != value)
			reverse_rotate_a(stack_a);
		while (find_place_in_b((*stack_b), value) > 0)
			reverse_rotate_b(stack_b);
		push_to_b(stack_a, stack_b);
	}
	else
	{
		while ((*stack_b)->value != value && find_place_in_a((*stack_a), value) > 0)
			reverse_rotate_rr(stack_a, stack_b);
		while ((*stack_b)->value != value)
			reverse_rotate_b(stack_b);
		while (find_place_in_a((*stack_a), value) > 0)
			reverse_rotate_a(stack_a);
		push_to_a(stack_a, stack_b);
	}
	return (-1);
}
