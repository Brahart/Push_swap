/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:07:25 by asinsard          #+#    #+#             */
/*   Updated: 2025/02/07 01:11:51 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	main(int ac, char **av)
{
	int		i;
	int		j;
	int		value;
	t_stack	*stack_a;
	char	**arg;

	stack_a = NULL;
	if (ac < 2)
	{
		ft_error("ERROR\nThe program need at least 1 argument");
		return (0);
	}
	i = 1;
	j = 0;
	if (ac == 2)
	{
		arg = check_arg(av[1]);
		av = arg;
		i = 0;
	}
	while (av[i])
	{
		value = check_atol(av[i], stack_a);
		add_to_list(&stack_a, value);
		i++;
	}
	if (check_is_sorted(stack_a))
	{
		free_list(stack_a);
		if (ac == 2)
			free_split(arg);
		return(0);
	}
	algo_sort(&stack_a);
	if (check_is_sorted(stack_a))
		ft_printf("\e[1;32mSUCCESS !!!\n\e[0m");
	// display_list(stack_a, "stack_a");
	if (ac == 2)
		free_split(arg);
	free_list(stack_a);
	return (0);
}
