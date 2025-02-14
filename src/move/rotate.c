/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:09:22 by asinsard          #+#    #+#             */
/*   Updated: 2025/02/13 23:19:29 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../libft/include/ft_printf.h"

void	rotate_a(t_stack **stack_a, bool flag)
{
	if (!(*stack_a) || (*stack_a)->next == *stack_a)
		return ;
	*stack_a = (*stack_a)->next;
	if (flag == true)
		ft_printf("ra\n");
}

void	rotate_b(t_stack **stack_b, bool flag)
{
	if (!(*stack_b) || (*stack_b)->next == *stack_b)
		return ;
	*stack_b = (*stack_b)->next;
	if (flag == true)
		ft_printf("rb\n");
}

void	rotate_rr(t_stack **stack_a, t_stack **stack_b, bool flag)
{
	rotate_a(stack_a, false);
	rotate_b(stack_b, false);
	if (flag == true)
		ft_printf("rr\n");
}
