/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:07:25 by asinsard          #+#    #+#             */
/*   Updated: 2025/02/13 23:54:55 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	char	**arg;

	a = NULL;
	if (ac < 2)
	{
		ft_error("ERROR\nThe program need at least 1 argument\n");
		return (0);
	}
	arg = create_stack(ac, av, &a);
	check_error(arg, ac, a);
	if (check_double(a))
		ft_free(ac, a, arg, true);
	if (check_is_sorted(a))
		ft_free(ac, a, arg, false);
	algo_sort(&a);
	ft_free(ac, a, arg, false);
	return (0);
}
