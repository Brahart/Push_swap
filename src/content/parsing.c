/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:46:00 by asinsard          #+#    #+#             */
/*   Updated: 2025/02/13 23:57:22 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../libft/include/libft.h"

int	check_double(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*runner;

	if (!stack || stack->next == stack)
		return (0);
	tmp = stack;
	while (tmp->next != stack)
	{
		runner = tmp->next;
		while (runner != stack)
		{
			if (tmp->content == runner->content)
				return (1);
			runner = runner->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

char	**check_arg(char *str)
{
	int		i;
	char	**array;

	array = NULL;
	i = 0;
	while (str[i])
	{
		if ((str[i] == ' ') || (str[i] >= '0')
			|| (str[i] <= '9'))
			i++;
		else
			return (NULL);
	}
	i = 0;
	array = ft_split(str, ' ');
	if (!array)
		exit(0);
	return (array);
}

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

int	check_atol(char *nbr, t_stack *list, int ac, char **arg)
{
	long int	i;

	i = 0;
	while (nbr[i])
	{
		if (nbr[i] == '-')
			i++;
		if ((nbr[i] < '0') || (nbr[i] > '9'))
		{
			ft_error("ERROR\nAll arguments are not numbers");
			ft_free(ac, list, arg, false);
		}
		i++;
	}
	i = ft_atol(nbr);
	if ((i < INT_MIN) || (i > INT_MAX))
	{
		ft_error(
			"ERROR\nOne argument is bigger than INT max or lower than INT min");
		ft_free(ac, list, arg, false);
	}
	return (i);
}
