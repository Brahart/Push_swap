/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrahamsinsard <abrahamsinsard@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:57:57 by asinsard          #+#    #+#             */
/*   Updated: 2025/02/12 15:17:36 by abrahamsins      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_error(const char *str)
{
	write(2, "\e[1;31m%s\e[0m\n", ft_strlen(str));
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
		return (NULL);
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
