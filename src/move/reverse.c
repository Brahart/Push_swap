/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:55:22 by asinsard          #+#    #+#             */
/*   Updated: 2025/02/03 19:54:34 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	reverse_rotate_a(t_stack **stack_a, bool flag)
{
	if (!stack_a || !(*stack_a) || (*stack_a)->next == *stack_a)
		return ;
	(*stack_a) = (*stack_a)->prev;
	if (flag == true)
		ft_printf("rra\n");
}

void	reverse_rotate_b(t_stack **stack_b, bool flag)
{
	if (!stack_b || !(*stack_b) || (*stack_b)->next == *stack_b)
		return ;
	(*stack_b) = (*stack_b)->prev;
	if (flag == true)
		ft_printf("rrb\n");
}

void	reverse_rotate_rr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate_a(stack_a, false);
	reverse_rotate_b(stack_b, false);
	ft_printf("rrr\n");
}
