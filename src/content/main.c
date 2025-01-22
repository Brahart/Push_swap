/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:07:25 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/22 01:53:58 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	main(int ac, char **av)
{
	int		i;
	int		value;
	t_pile	*pile_a;
	t_pile	*pile_b;
	char	**arg;

	pile_a = NULL;
	pile_b = NULL;
	if (ac < 2)
	{
		ft_error("ERROR\nThe program need at least 1 argument");
		return (0);
	}
	i = 1;
	arg = check_arg(av[1]);
	if (arg)
	{
		av = arg;
		i = 0;
	}
	while (av[i])
	{
		value = check_atol(av[i], pile_a);
		ft_printf("[%d]\nvalue = %d\n", i, value);
		add_to_list(&pile_a, value);
		add_to_list(&pile_b, value);
		i++;
	}
	display_list(pile_a, "pile_a");
	display_list(pile_b, "pile_b");
	// push_to_b(&pile_a, &pile_b);
	// display_list(pile_a, "pile_a");
	// display_list(pile_b, "pile_b");
	free_list(pile_b);
	free_list(pile_a);
	free_split(arg);
	return (0);
}
