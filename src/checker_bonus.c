/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 00:25:17 by asinsard          #+#    #+#             */
/*   Updated: 2025/02/14 04:22:31 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft/include/libft.h"
#include "../include/push_swap.h"

void	delete_stack(t_stack **stack)
{
	(*stack)->next = NULL;
	(*stack)->prev = NULL;
	(*stack) = NULL;
}

int	check_instructions(char *line, t_stack **a, t_stack **b)
{
	if (!line)
		return (0);
	if (ft_strncmp(line, "sa\n", 3) == 0)
		swap_a(a, false);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		push_to_a(a, b, false);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		push_to_b(a, b, false);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		rotate_a(a, false);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rotate_b(b, false);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rotate_rr(a, b, false);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		reverse_rotate_a(a, false);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		reverse_rotate_b(b, false);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		reverse_rotate_rr(a, b, false);
	else
		return (0);
	return (1);
}

void	check_ok_or_ko(char *line, t_stack **a, t_stack **b)
{
	int	len_b;

	len_b = stack_size(*b);
	if (!line)
		return ;
	if (ft_strncmp(line, "pa\n", 3) == 0 && len_b == 1)
	{
		push_to_b(a, b, false);
		(*b)->next = NULL;
		(*b)->prev = NULL;
		*b = NULL;
		return ;		
	}
	check_instructions(line, a, b);
	
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;
	char	**arg;

	if (ac < 2)
		return (0);
	a = NULL;
	b = NULL;
	arg = create_stack(ac, av, &a);
	check_error(arg, ac, a);
	line = get_next_line(0);
	check_ok_or_ko(line, &a, &b);
	while (line)
	{
		free(line);
		line = get_next_line(0);
		check_ok_or_ko(line, &a, &b);
	}
	if (!check_is_sorted(a) || stack_size(b) != 0)
		write(2, "KO\n", 3);
	if (check_is_sorted(a) && stack_size(b) == 0)
		write(1, "OK\n", 3);
	ft_free(ac, a, arg, false);
	return (0);
}
