/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:57:57 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/22 01:48:48 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_error(const char *str)
{
	ft_printf("\e[1;31m%s\n", str);
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
			return NULL;
	}
	i = 0;
	array = ft_split(str, ' ');
	if (!array)
		return NULL;
	return (array);
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