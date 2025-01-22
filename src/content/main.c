/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:07:25 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/22 20:55:06 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	main(int ac, char **av)
{
	int		i;
	int		value;
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**arg;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
	{
		ft_error("ERROR\nThe program need at least 1 argument");
		return (0);
	}
	i = 1;
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
	if (check_is_sorted(&stack_a))
	{
		free_list(stack_a);
		if (ac == 2)
			free_split(arg);
		return(0);
	}
	if (!check_double(&stack_a))
		algo_sort(&stack_a);
	else
		ft_error("ERROR\nThe stack contains double");
	if (ac == 2)
		free_split(arg);
	free_list(stack_a);
	return (0);
}
