/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:57:57 by asinsard          #+#    #+#             */
/*   Updated: 2025/02/14 20:55:06 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../libft/include/libft.h"

void	ft_error(const char *str)
{
	write(2, str, ft_strlen(str));
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	ft_free(int ac, t_stack *a, char **arg, bool flag)
{
	free_stack(a);
	if (ac == 2)
		free_split(arg);
	if (flag == true)
	{
		ft_error("ERROR\n");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

void	check_error(char **arg, int ac, t_stack *a)
{
	if (!a && arg)
	{
		free_split(arg);
		ft_error("ERROR\nProblem with allocation of stack");
		exit (EXIT_FAILURE);
	}
	else if (!arg && ac == 2)
	{
		if (a)
			free_stack(a);
		ft_error("ERROR\nproblem with split");
		exit(EXIT_FAILURE);
	}
	if (check_double(a))
		ft_free(ac, a, arg, true);
}
