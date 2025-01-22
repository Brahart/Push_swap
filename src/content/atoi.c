/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:10:07 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/22 16:38:07 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

long int	ft_atol(const char *nptr)
{
	int			i;
	long int	n;
	int			neg;

	i = 0;
	n = 0;
	neg = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n *= 10;
		n += nptr[i] - '0';
		i++;
	}
	return (n * neg);
}

int	check_atol(char *nbr, t_stack *list)
{
	long int	i;

	i = 0;
	while (nbr[i])
	{
		if (nbr[i] == '-')
			i++;
		if ((nbr[i] < '0') || (nbr[i] > '9'))
		{
			free_list(list);
			ft_error("ERROR\nAll arguments are not numbers");
			exit(0);
		}
		i++;
	}
	i = ft_atol(nbr);
	if ((i < INT_MIN) || (i > INT_MAX))
	{
		ft_error(
			"ERROR\nOne argument is bigger than INT max or lower than INT min");
		free_list(list);
		exit(0);
	}
	return (i);
}
