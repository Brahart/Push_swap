/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:55:19 by asinsard          #+#    #+#             */
/*   Updated: 2025/02/14 21:05:54 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../libft/include/ft_printf.h"

t_stack	*del_from(t_stack **src)
{
	t_stack	*tmp;

	tmp = NULL;
	if (*src)
	{
		tmp = (*src);
		if ((*src)->next == *src)
			(*src) = NULL;
		else
		{
			(*src) = (*src)->next;
			(*src)->prev = tmp->prev;
			tmp->prev->next = (*src);
		}
	}
	return (tmp);
}

void	add_to(t_stack **dest, t_stack *tmp)
{
	if (tmp)
	{
		if (*dest)
		{
			tmp->next = (*dest);
			tmp->prev = (*dest)->prev;
			(*dest)->prev->next = tmp;
			(*dest)->prev = tmp;
		}
		else
		{
			tmp->next = tmp;
			tmp->prev = tmp;
		}
		(*dest) = tmp;
	}
}

void	push_to_a(t_stack **a, t_stack **b, bool flag)
{
	t_stack	*tmp;

	tmp = del_from(b);
	add_to(a, tmp);
	if (flag == true)
		ft_printf("pa\n");
}

void	push_to_b(t_stack **a, t_stack **b, bool flag)
{
	t_stack	*tmp;

	tmp = del_from(a);
	add_to(b, tmp);
	if (flag == true)
		ft_printf("pb\n");
}
